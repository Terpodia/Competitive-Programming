#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;

const ll INF = 1e18;

bool f(ll d, vector<ll> h, ll hi) {
  ll cnt1 = (d + 1) / 2, cnt2 = d / 2;

  for (int i = 0; i < sz(h); i++) {
    if (cnt2 == 0) break;
    if ((hi - h[i]) % 2 != 0) continue;
    ll r = min(cnt2, (hi - h[i]) / 2);
    cnt2 -= r, h[i] += 2 * r;
  }
  for (int i = 0; i < sz(h); i++) {
    if (cnt2 == 0) break;
    if ((hi - h[i]) % 2 == 0) continue;
    ll r = min(cnt2, (hi - h[i]) / 2);
    cnt2 -= r, h[i] += 2 * r;
  }
  for (int i = 0; i < sz(h); i++) {
    if (cnt1 == 0) break;
    ll r = min(cnt1, hi - h[i]);
    cnt1 -= r, h[i] += r;
  }
  for (int i = 0; i < sz(h) - 1; i++)
    if (h[i] != h[i + 1]) return false;

  return true;
}

void solve(vector<ll> h) {
  ll l = 0, r = INF;
  while (r > l) {
    ll mid = l + (r - l) / 2;
    ll hi = *max_element(all(h));
    if (f(mid, h, hi) || f(mid, h, hi + 1))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld\n", r);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> h(n);
    for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
    solve(h);
  }
  return 0;
}

