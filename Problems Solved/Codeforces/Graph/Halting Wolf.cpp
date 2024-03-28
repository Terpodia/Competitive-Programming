#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

typedef tuple<int, ll, ll> edge;
struct max_flow {
  int V;
  vector<edge> EL;
  vector<vector<int>> AL;
  vector<int> d, last;
  max_flow(int N) : V(N) {
    EL.clear();
    AL.assign(V, vector<int>());
  }
  void add_edge(int u, int v, ll c) {
    AL[u].pb(SZ(EL)), EL.emplace_back(v, c, 0);
    AL[v].pb(SZ(EL)), EL.emplace_back(u, 0, 0);
  }
  bool bfs(int s, int t) {
    d.assign(V, -1);
    d[s] = 0;
    queue<int> q({s});
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == t) break;
      for (auto& i : AL[u]) {
        auto& [v, c, f] = EL[i];
        if (d[v] != -1 || c - f == 0) continue;
        d[v] = d[u] + 1, q.push(v);
      }
    }
    return d[t] != -1;
  }
  ll dfs(int u, int t, ll f = INF) {
    if (u == t || f == 0) return f;
    for (int& i = last[u]; i < SZ(AL[u]); i++) {
      auto& [v, c, flow] = EL[AL[u][i]];
      if (d[u] + 1 != d[v]) continue;
      if (ll pushed = dfs(v, t, min(f, c - flow))) {
        flow += pushed;
        auto& rflow = get<2>(EL[AL[u][i] ^ 1]);
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  ll dinic(int s, int t) {
    ll mf = 0;
    while (bfs(s, t)) {
      last.assign(V, 0);
      while (ll f = dfs(s, t)) mf += f;
    }
    return mf;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  max_flow g(n + 1);

  fore(i, 0, n) {
    string s;
    cin >> s;
    if (s == "*") {
      int x;
      cin >> x;
      x--;
      if (x == 0) x = n;
      if (i == 0)
        g.add_edge(0, x, INF), g.add_edge(n, x, INF);
      else
        g.add_edge(i, x, INF);
    } else {
      int k = stoi(s);
      fore(j, 0, k) {
        int x;
        cin >> x;
        x--;
        if (x == 0) x = n;
        if (i == 0)
          g.add_edge(0, x, 1), g.add_edge(n, x, 1);
        else
          g.add_edge(i, x, 1);
      }
    }
  }
  ll mf = g.dinic(0, n);
  if (mf == INF)
    cout << "*\n";
  else
    cout << mf + 1 << "\n";
  return 0;
}
