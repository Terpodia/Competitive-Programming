#define FASTCOMP
#ifdef FASTCOMP
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
#include <cstring>
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

const int MOD = 1e9 + 7;
const ll INF = 1e9;

ll comb[5010][5010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ll p;
  cin >> n >> p;

  forn(i, n + 10) comb[i][0] = 1;
  fore(i, 1, n + 10) fore(j, 1, i + 1) comb[i][j] =
      (comb[i - 1][j] + comb[i - 1][j - 1]) % p;

  ll fact[2 * n];
  fact[0] = 1;
  fore(i, 1, 2 * n) fact[i] = (fact[i - 1] * (ll)i) % p;

  int m = (n + 1) / 2 - 1;
  ll res = 0;
  forn(x, m + 1) {
    if (x == 0) {
      if (n % 2 == 1) continue;
      ll M = n - x - 1, L = n / 2 + x - (n + 1) / 2 + 1;
      res += fact[M - 1] * L;
      res %= p;
    }
    forn(s, x) {
      ll M = n - x - 1, L = n / 2 + x - (n + 1) / 2 + 1;
      res += (((comb[x - 1][s] * fact[M + s - 1]) % p) * L) % p;
      res %= p;
    }
  }
  res = (res * (ll)n) % p;
  cout << res << "\n";
  return 0;
}