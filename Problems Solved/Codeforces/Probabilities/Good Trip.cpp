#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1LL) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1LL;
  }
  return ret;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;

  cin >> tt;
  while (tt--) {
    ll n;
    int m, k;
    cin >> n >> m >> k;
    ll sum = 0;
    fore(i, 0, m) {
      int a, b;
      ll f;
      cin >> a >> b >> f;
      sum += f;
    }
    sum %= MOD;
    ll p = (n * (n - 1)) / 2;
    p %= MOD;
    ll ans = 0;
    fore(i, 0, k) {
      ans += (sum * inv(p)) % MOD, ans %= MOD;
      sum += ((m * inv(p)) % MOD), sum %= MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}
