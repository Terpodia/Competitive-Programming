#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, n) for (int i = 0; i < n; i++)
#define printv(v)                      \
  if (1) {                             \
    for (auto i : v) cerr << i << " "; \
    cerr << endl;                      \
  }
#define fst first
#define snd second
#define mp make_pair
const int MAXN = 200010;
const ll INF = 1e18;

vector<int> g[2][MAXN];
int comp[MAXN];
bool vis[MAXN];
vector<int> st;
int n;

ll vh[MAXN];
int sz[MAXN];

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
  st.resize(0);
  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs1(i);
  reverse(st.begin(), st.end());
  for (int u : st)
    if (comp[u] == -1) dfs2(u, u);
}

vector<int> H[MAXN];

pair<int, ll> dp[MAXN];

pair<int, ll> f(int u) {
  if (dp[u] != mp(-1, -1LL)) return dp[u];
  pair<int, ll> &ret = dp[u];
  ret = mp(sz[u], vh[u]);
  for (int v : H[u]) {
    pair<int, ll> res = f(v);
    if (res.fst + sz[u] > ret.fst)
      ret = mp(res.fst + sz[u], vh[u] + res.snd);
    else if (res.fst + sz[u] == ret.fst)
      ret.snd = min(ret.snd, res.snd + vh[u]);
  }
  return ret;
}

void solve() {
  int m;
  cin >> n >> m;
  forn(i, n) {
    comp[i] = -1;
    dp[i] = {-1, -1};
  }
  vector<ll> v(n);
  forn(i, n) cin >> v[i];
  forn(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[0][a].push_back(b);
    g[1][b].push_back(a);
  }
  scc();

  forn(i, n) {
    vh[comp[i]] += v[i];
    sz[comp[i]]++;
    for (auto j : g[0][i])
      if (comp[i] != comp[j]) {
        H[comp[i]].push_back(comp[j]);
      }
  }

  pair<int, ll> res = mp(0, INF);

  for (int i = 0; i < n; i++) {
    pair<int, ll> p = f(i);
    if (p.fst > res.fst)
      res = p;
    else if (p.fst == res.fst)
      res.snd = min(res.snd, p.snd);
  }

  cout << res.fst << " " << res.snd << "\n";

  // end
  forn(i, n) {
    g[0][i].clear();
    g[1][i].clear();
    vis[i] = 0;
    vh[i] = 0;
    sz[i] = 0;
    H[i] = vector<int>();
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
