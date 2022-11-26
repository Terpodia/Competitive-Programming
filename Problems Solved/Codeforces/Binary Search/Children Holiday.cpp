// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n............................................\n";

typedef long long ll;

const int MAXN = 1000;
const ll INF = 1e18;

int n;
ll m;
ll t[MAXN], z[MAXN], y[MAXN];
ll cnt[MAXN];

ll bs(ll T, int i) {
  ll l = 0, r = (ll)1e15;
  while (r > l) {
    ll mid = l + (r - l + 1) / 2;
    ll tt = (mid == 0) ? 0 : mid * t[i] + ((mid - 1) / z[i]) * y[i];
    if (T >= tt)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

bool can(ll T) {
  ll acc = 0;
  ll cnt2[n];

  rep(i, 0, n) {
    cnt2[i] = bs(T, i);
    acc += cnt2[i];
  }
  if (acc >= m) rep(i, 0, n) cnt[i] = cnt2[i];
  return acc >= m;
}

ll solve() {
  ll l = 0, r = INF;
  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  scanf("%lld%d", &m, &n);
  rep(i, 0, n) scanf("%lld%lld%lld", t + i, z + i, y + i);
  ll T = solve();
  printf("%lld\n", T);
  ll acc = 0;
  rep(i, 0, n) acc += cnt[i];
  rep(i, 0, n) if (acc > m) {
    ll r = min(acc - m, cnt[i]);
    acc -= r;
    cnt[i] -= r;
  }
  rep(i, 0, n) printf("%lld%c", cnt[i], " \n"[i == n - 1]);
  return 0;
}
