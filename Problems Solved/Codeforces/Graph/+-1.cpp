#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<cstring>
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

const int MAXN = 2000;

vector<int> g[2][MAXN];
int comp[MAXN];  // init with -1
bool vis[MAXN];
vector<int> st;
int n;

void dfs1(int u) {
  vis[u] = true;
  for (int v : g[1][u])
    if (!vis[v]) dfs1(v);
  st.push_back(u);
}
void dfs2(int u, int idx) {
  comp[u] = idx;
  for (int v : g[0][u])
    if (comp[v] == -1) dfs2(v, idx);
}
void scc() {
  for (int i = 0; i < 2 * n + 1; i++)
    if (!vis[i]) dfs1(i);
  reverse(st.begin(), st.end());
  for (int u : st)
    if (comp[u] == -1) dfs2(u, u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;

    int a[3][n];
    forn(i, 3) forn(j, n) cin >> a[i][j];

    forn(i, 2 * n + 1) {
      comp[i] = -1;
      vis[i] = false;
      st.clear();
      g[0][i].clear();
      g[1][i].clear();
    }

    forn(j, n) {
      forn(i, 3) fore(k, i + 1, 3) {
        g[0][-a[i][j] + n].pb(a[k][j] + n);
        g[1][a[k][j] + n].pb(-a[i][j] + n);

        g[0][-a[k][j] + n].pb(a[i][j] + n);
        g[1][a[i][j] + n].pb(-a[k][j] + n);
      }
    }
    scc();

    bool res = true;
    fore(i, 1, n + 1) { res &= comp[i + n] != comp[-i + n]; }
    if (res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
