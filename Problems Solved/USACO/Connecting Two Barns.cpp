#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int aux;

typedef long long ll;

const int MAXN = 1e5;
ll INF = 1e18;

int n, m;
vector<int> G[MAXN];
bool vis[MAXN];

void DFS(int u, vector<ll>& cc) {
  vis[u] = true;
  cc.push_back(u);
  for (int v : G[u])
    if (!vis[v]) DFS(v, cc);
}

ll solve() {
  vector<ll> cc[MAXN];
  int numCC = 0;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) DFS(i, cc[numCC]), numCC++;
  }

  for (int i = 0; i < numCC; i++) sort(cc[i].begin(), cc[i].end());

  ll a = 0, b = 0;

  for (int i = 0; i < numCC; i++) {
    for (ll v : cc[i]) {
      if (v == 0)
        a = i;
      else if (v == n - 1)
        b = i;
    }
  }

  if (a == b) return 0;

  ll ret = INF;

  ll dist[2][numCC];

  for (int i = 0; i < numCC; i++) {
    dist[0][i] = INF;
    if (i == a || i == b) continue;
    for (ll j : cc[i]) {
      auto it = lower_bound(cc[a].begin(), cc[a].end(), j);
      if (it == cc[a].end()) it--;

      dist[0][i] = min(dist[0][i], (*it - j) * (*it - j));
      if (it != cc[a].begin()) {
        it--;
        dist[0][i] = min(dist[0][i], (*it - j) * (*it - j));
      }
    }
  }

  for (int i = 0; i < numCC; i++) {
    dist[1][i] = INF;
    if (i == a || i == b) continue;
    for (ll j : cc[i]) {
      auto it = lower_bound(cc[b].begin(), cc[b].end(), j);
      if (it == cc[b].end()) it--;

      dist[1][i] = min(dist[1][i], (*it - j) * (*it - j));
      if (it != cc[b].begin()) {
        it--;
        dist[1][i] = min(dist[1][i], (*it - j) * (*it - j));
      }
    }
  }

  for (ll j : cc[a]) {
    auto it = lower_bound(cc[b].begin(), cc[b].end(), j);
    if (it == cc[b].end()) it--;
    ret = min(ret, (*it - j) * (*it - j));
    if (it != cc[b].begin()) {
      it--;
      ret = min(ret, (*it - j) * (*it - j));
    }
  }

  for (int i = 0; i < numCC; i++) {
    if (i == a || i == b) continue;
    ret = min(ret, dist[0][i] + dist[1][i]);
  }

  return ret;
}

int main() {
  int TC;
  aux = scanf("%d", &TC);
  while (TC--) {
    aux = scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      aux = scanf("%d%d", &u, &v);
      G[u - 1].push_back(v - 1);
      G[v - 1].push_back(u - 1);
    }

    printf("%lld\n", solve());

    for (int i = 0; i < n; i++) G[i].clear();
    memset(vis, false, sizeof(vis));
  }

  return 0;
}
