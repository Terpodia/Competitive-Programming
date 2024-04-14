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

const int MOD = 1e9 + 7, MAXN = 1e6 + 10;
const ll INF = 1e9;

int n;
string s[MAXN];

int dp[MAXN][3];

set<int> x;

int solve(int i, int cnt) {
  if (i == n) return 0;
  int& ret = dp[i][cnt];
  if (ret != -1) return ret;

  ret = INF;

  forn(k, min(3, SZ(s[i]))) {
    if (x.find(s[i][k] - 'A') == x.end())
      cnt++;
    else
      cnt = 0;
    if (cnt > 2) break;
    ret = min(ret, solve(i + 1, cnt) + k + 1);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) cin >> s[i];
  memset(dp, -1, sizeof(dp));
  x.insert(0);
  x.insert('E' - 'A');
  x.insert('I' - 'A');
  x.insert('O' - 'A');
  x.insert('U' - 'A');
  x.insert('Y' - 'A');
  int res = solve(0, 0);
  if (res == INF)
    cout << "*\n";
  else
    cout << res << "\n";
  return 0;
}
