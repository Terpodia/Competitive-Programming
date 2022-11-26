// Si puedes imaginarlo, puedes programarlo
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n.......................................\n";

typedef long long ll;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;

int N, cnt;
vector<pair<int, ll>> g[MAXN][2];
bool vis[MAXN];
stack<int> S;
ll sum, lo;

void dfs(int u, int j = 1) {
  vis[u] = true;
  cnt++;

  for (auto& [v, w] : g[u][j]) {
    sum += w;
    lo = min(lo, w);
    if (!vis[v]) dfs(v, j);
  }
  if (j == 1) S.push(u);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N;
  rep(i, 0, N) {
    int v;
    ll w;
    cin >> v >> w;
    v--;
    g[i][0].push_back({v, w});
    g[v][1].push_back({i, w});
  }
  rep(i, 0, N) if (!vis[i]) dfs(i);

  ll ans = 0;
  memset(vis, false, sizeof(vis));

  while (!S.empty()) {
    int u = S.top();
    S.pop();
    if (!vis[u]) {
      cnt = 0;
      sum = 0;
      lo = INF;
      dfs(u, 0);

      if (cnt == 1)
        ans += sum;
      else
        ans += sum - lo;
    }
  }

  cout << ans << "\n";

  return 0;
}
