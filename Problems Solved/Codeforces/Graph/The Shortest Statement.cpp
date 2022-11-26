#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

struct union_find {
  vector<int> p, sz;

  union_find(int n) {
    p = vector<int>(n);
    iota(all(p), 0);
    sz = vector<int>(n, 1);
  }

  int find(int x) { return (p[x] == x) ? x : p[x] = find(p[x]); }

  bool merge(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return false;
    if (sz[pu] < sz[pv]) swap(pu, pv);

    sz[pu] += sz[pv];
    p[pv] = pu;

    return true;
  }
};

struct node {
  int to;
  ll w;
};

const int MAXN = 1e5, MAXLOG = 20;
const ll INF = 1e18;

int n, m;

vector<node> G[MAXN], tree[MAXN];

int H[MAXN], anc[MAXN][MAXLOG];
ll D[MAXN];

void dfs(int u, int p = -1, ll val = 0) {
  if (p != -1) H[u] = H[p] + 1, D[u] = D[p] + val;

  anc[u][0] = p;

  for (int i = 1; i < MAXLOG; i++)
    if (anc[u][i - 1] != -1) anc[u][i] = anc[anc[u][i - 1]][i - 1];

  for (auto& [v, w] : tree[u])
    if (v != p) dfs(v, u, w);
}

int lca(int u, int v) {
  if (H[v] < H[u]) swap(v, u);

  for (int i = MAXLOG - 1; i > -1; i--)
    if (anc[v][i] != -1 && H[anc[v][i]] >= H[u]) v = anc[v][i];

  if (u == v) return u;

  for (int i = MAXLOG - 1; i > -1; i--)
    if (anc[u][i] != -1 && anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];

  return anc[u][0];
}

vector<ll> dijkstra(int s) {
  priority_queue<pair<ll, int>> pq;
  vector<ll> dist(n, INF);

  pq.push({-0, s});
  dist[s] = 0;

  while (!pq.empty()) {
    auto [p, u] = pq.top();
    pq.pop();
    if (dist[u] != -p) continue;

    for (auto& [v, w] : G[u]) {
      if (w - p < dist[v]) {
        dist[v] = w - p;
        pq.push({-dist[v], v});
      }
    }
  }

  return dist;
}

int main() {
  scanf("%d%d", &n, &m);

  union_find uf(n);
  unordered_set<int> uset;

  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    u--, v--;

    G[u].push_back({v, w});
    G[v].push_back({u, w});

    if (uf.merge(u, v)) {
      tree[u].push_back({v, w});
      tree[v].push_back({u, w});
    }

    else
      uset.insert(u), uset.insert(v);
  }

  vector<vll> dist(sz(uset), vll(n));
  int j = 0;

  for (auto i = uset.begin(); i != uset.end(); i++, j++) dist[j] = dijkstra(*i);

  memset(anc, -1, sizeof(anc));
  dfs(0);

  int q;
  scanf("%d", &q);

  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    ll ans = D[u] + D[v] - 2 * D[lca(u, v)];

    for (int i = 0; i < sz(dist); i++) {
      ans = min(ans, dist[i][u] + dist[i][v]);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
