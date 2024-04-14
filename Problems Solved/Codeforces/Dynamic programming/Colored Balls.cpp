#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#endif
using namespace std;
#ifndef FASTCOMP
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
#endif

// MACROS
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define sz(x) SZ(x)
#define len(x) SZ(x)
#define all(x) x.begin(), x.end()
#define esta(x, c) ((c).find(x) != (c).end())
// FOR
#define fore(i, a, b) for (auto i = a, to = b; i < to; ++i)
#define form(i, n, m) fore(i, n, m)
#define forn(i, n) form(i, 0, n)
#define dfor(i, n) for (int i = n; i-- > 0;)
#define forall(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
// DEBUG
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<
#define printv(v)                      \
  if (1) {                             \
    for (auto _ : v) cerr << _ << " "; \
    cerr << endl;                      \
  }

typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
const ll INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll a[n];
  forn(i, n) cin >> a[i];
  sort(a, a + n);

  ll dp[n + 10][5010];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  fore(i, 1, n + 1) fore(j, 0, 5010) {
    dp[i][j] += dp[i - 1][j];
    if (j - a[i - 1] >= 0) dp[i][j] += dp[i - 1][j - a[i - 1]];
    dp[i][j] %= MOD;
  }

  ll ans = 0;

  fore(i, 1, n + 1) {
    fore(j, a[i - 1], 5010LL) {
      if (j - a[i - 1] < a[i - 1])
        ans += a[i - 1] * (dp[i][j] - dp[i - 1][j]);
      else
        ans += (dp[i][j] - dp[i - 1][j]) * (ll)((j + 1) / 2);
    }
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
  }
  cout << ans << "\n";

  return 0;
}
