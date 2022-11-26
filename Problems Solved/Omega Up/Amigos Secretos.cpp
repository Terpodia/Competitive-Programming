// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line                                                                 \
  cout << "\n.............................................................." \
          "\n";

typedef long long ll;

const ll MOD = 998244353;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  ll f[n + 1], g[n + 1], factorial[n + 1];

  factorial[0] = 1;
  rep(i, 1, n + 1) factorial[i] = (factorial[i - 1] * (ll)i) % MOD;

  f[0] = g[0] = 1;
  rep(i, 1, k) f[i] = 0, g[i] = 1;

  rep(i, k, n + 1) {
    f[i] = (factorial[i - 1] * g[i - k]) % MOD;
    g[i] = g[i - 1];
    g[i] += (f[i] * inv(factorial[i])) % MOD;
    g[i] %= MOD;
  }
  printf("%lld\n", f[n]);
  return 0;
}
