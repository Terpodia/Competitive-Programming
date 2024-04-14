#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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

const int MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAXN = 1e3 + 10;

int n, k, a[MAXN][MAXN];
vector<int> dp[MAXN];

bool cmp(int x, int y) { return x > y; }

vector<int>& solve(int i) {
  if (i >= n) {
    vector<int> ret(1, 0);
    return dp[i] = ret;
  }
  vector<int>& ret = dp[i];
  if (SZ(ret)) return ret;

  priority_queue<tuple<int, int, int>> pq;

  fore(j, i, n) { pq.push({solve(j + 2)[0] + a[i][j], j + 2, 0}); }
  pq.push({solve(i + 1)[0], i + 1, 0});
  while (!pq.empty() && SZ(ret) < k) {
    auto [res, idx, j] = pq.top();
    pq.pop();
    ret.pb(res);
    if (SZ(solve(idx)) == j + 1) continue;

    if (idx - 2 >= i)
      pq.push({solve(idx)[j + 1] + a[i][idx - 2], idx, j + 1});
    else
      pq.push({solve(idx)[j + 1], idx, j + 1});
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    forn(i, n) fore(j, i, n) { cin >> a[i][j]; }
    forn(i, n + 1) dp[i].clear();
    vector<int> ans = solve(0);
    for (int i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
