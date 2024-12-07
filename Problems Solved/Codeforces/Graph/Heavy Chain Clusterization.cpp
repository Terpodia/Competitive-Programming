#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int INF = 1e9;

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
    AL[u].pb(len(EL)), EL.emplace_back(v, c, 0);
    AL[v].pb(len(EL)), EL.emplace_back(u, 0, 0);
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
    for (int& i = last[u]; i < len(AL[u]); i++) {
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
  // freopen("heavy.in","r",stdin);
  // freopen("heavy.out","w",stdout);
  int n, k;
  cin >> n >> k;
  string s[n];
  forn(i, n) cin >> s[i];
  map<string, vector<int>> pref, suf;
  forn(i, n) {
    string p = s[i].substr(0, k);
    pref[p].pb(i + 1);
    p = s[i].substr(len(s[i]) - k, k);
    suf[p].pb(i + 1);
  }
  max_flow mf(2 * n + 2);
  fore(i, 1, n + 1) mf.add_edge(0, i, 1);
  for (auto& [_, v] : pref) {
    forn(i, len(v)) fore(j, i + 1, len(v)) {
      mf.add_edge(v[i], v[j] + n, 2 * n + 3);
    }
  }
  for (auto& [_, v] : suf) {
    forn(i, len(v)) fore(j, i + 1, len(v)) {
      mf.add_edge(v[j], v[i] + n, 2 * n + 3);
    }
  }
  fore(i, 1, n + 1) mf.add_edge(i + n, 2 * n + 1, 1);
  mf.dinic(0, 2 * n + 1);

  map<string, vector<int>> ans;
  fore(i, 1, n + 1) {
    if (mf.d[i] < 0)
      ans[s[i - 1].substr(0, k)].pb(i);
    else
      ans[s[i - 1].substr(len(s[i - 1]) - k, k)].pb(i);
  }
  cout << len(ans) << "\n";
  /*
  for(auto& [_, v] : ans){
          cout << len(v) << " ";
          for(int i : v) cout << i << " ";
          cout<<"\n";
  }
  */
  return 0;
}
