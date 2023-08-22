#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 11;

int n, m;

vector<int> g[2][MAXN];
vector<ll> w[MAXN];

vector<pair<int, ll>> dag[MAXN];
ll a[MAXN];

int comp[MAXN];
bool vis[MAXN];
vector<int> st;

ll dp[MAXN], sum[20008], sqr_sum[20008];

ll get(ll p) {
  int l = 0, r = (int)2e4 + 7;
  while (r > l) {
    int mid = l + ((r - l + 1) >> 1);
    if (p >= sum[mid])
      l = mid;
    else
      r = mid - 1;
  }
  ll ret = p * ((ll)l + 1LL) - ((sum[l] + sqr_sum[l]) >> 1LL);
  return ret;
}

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
  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs1(i);
  reverse(st.begin(), st.end());
  for (int u : st)
    if (comp[u] == -1) dfs2(u, u);
}

void solve() {
  int s;
  cin >> s;
  s--;

  int out[n];
  vector<int> p[n];
  for (int i = 0; i < n; i++) {
    out[i] = (int)dag[i].size();
    for (auto [v, b] : dag[i]) p[v].push_back(i);
  }
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (out[i] == 0) q.push(i);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    dp[u] = a[u];
    for (auto& [v, b] : dag[u]) {
      dp[u] = max(dp[u], a[u] + b + dp[v]);
    }
    for (int& v : p[u]) {
      out[v]--;
      if (out[v] == 0) q.push(v);
    }
  }
  cout << dp[comp[s]] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (ll i = 1; i < (ll)20008; i++) {
    sum[i] = sum[i - 1] + i;
    sqr_sum[i] = sqr_sum[i - 1] + i * i;
  }

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll p;
    cin >> u >> v >> p;
    u--, v--;
    g[0][u].push_back(v);
    g[1][v].push_back(u);
    w[u].push_back(p);
  }
  memset(comp, -1, sizeof(comp));
  scc();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)g[0][i].size(); j++) {
      int v = g[0][i][j];
      if (comp[i] != comp[v])
        dag[comp[i]].push_back(make_pair(comp[v], w[i][j]));
      else {
        a[comp[i]] += get(w[i][j]);
      }
    }
  }
  solve();
  return 0;
}
