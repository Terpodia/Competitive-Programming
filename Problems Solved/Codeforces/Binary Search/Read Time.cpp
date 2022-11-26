#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll INF = 1e18;

int n, m;
vector<ll> a, b;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool check(ll t) {
  int i = 0, j = 0;
  ll cnt = 0;

  vector<ll> h = a, p = b;

  while (i < n && j < m) {
    if (p[j] >= h[i]) {
      if (p[j] - h[i] + cnt > t) {
        cnt = 0;
        i++;
      } else {
        cnt += p[j] - h[i];
        h[i] = p[j];
        j++;
      }
    }

    else {
      if (h[i] - p[j] > t) return false;
      ll p1 = p[j] + t - (h[i] - p[j]);
      ll p2 = (t - h[i] + p[j]) / 2 + h[i];

      ll x = max(p1, p2);

      while (j < m && p[j] <= x) j++;
      i++;
    }
  }

  return (j == m);
}

ll solve() {
  ll l = 0, r = INF;

  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }

  return r;
}

int main() {
  fastIO();

  cin >> n >> m;
  a = vector<ll>(n);
  b = vector<ll>(m);

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  cout << solve() << "\n";

  return 0;
}
