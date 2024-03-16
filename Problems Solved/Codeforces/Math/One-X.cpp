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

const ll MOD = 998244353;

struct Func {
  ll k, b;
  Func() {}
  Func(ll _k, ll _b) : k(_k), b(_b) {}
  ll operator()(ll x) const {
    x %= MOD;
    return ((k * x) % MOD + b) % MOD;
  }
  Func operator+(Func f) const {
    Func ret(k + f.k, b + f.b);
    ret.k %= MOD, ret.b %= MOD;
    return ret;
  }
};

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1LL) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1LL;
  }
  return ret;
}

Func comb(Func f, Func g) {
  Func ret(f.k * g.k, f.b + f.k * g.b);
  ret.k %= MOD, ret.b %= MOD;
  return ret;
}

map<ll, Func> dp;

Func l(2, 0), r(2, 1);

Func solve(ll n) {
  if (dp.find(n) != dp.end()) return dp[n];
  if (n == 1) return dp[n] = Func(1, 0);

  ll a = (binpow(2, (n + 1) / 2) - 1 + MOD) % MOD;
  ll b = (binpow(2, n / 2) - 1 + MOD) % MOD;
  ll k = (a * b) % MOD;

  Func resl = comb(solve((n + 1) / 2), l);
  Func resr = comb(solve(n / 2), r);

  Func ret = Func(k, 0) + resl + resr;
  ret.k %= MOD, ret.b %= MOD;

  return dp[n] = ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    cout << solve(n)(1) << "\n";
  }
  return 0;
}
