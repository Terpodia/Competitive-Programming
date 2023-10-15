#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)

const int INF = 1e5;

struct edge {
  int v, cap, flow;
  edge(int _v, int _cap, int _flow) : v(_v), cap(_cap), flow(_flow) {}
};

struct max_flow {
  int V;
  vector<vector<int>> AL;
  vector<edge> EL;
  vector<int> d, last;
  max_flow(int N) : V(N) {
    AL.assign(V, vector<int>());
    EL.clear();
  }
  void add_edge(int u, int v, int c) {
    AL[u].push_back(SZ(EL)), EL.emplace_back(v, c, 0);
    AL[v].push_back(SZ(EL)), EL.emplace_back(u, 0, 0);
  }
  bool bfs(int s, int t) {
    d.assign(V, -1);
    d[s] = 0;
    queue<int> q({s});
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == t) break;
      for (int& i : AL[u]) {
        int &v = EL[i].v, &cap = EL[i].cap, &flow = EL[i].flow;
        if (d[v] != -1 || cap - flow == 0) continue;
        d[v] = d[u] + 1, q.push(v);
      }
    }
    return d[t] != -1;
  }
  int dfs(int u, int t, int f = INF) {
    if (u == t || f == 0) return f;
    for (int& i = last[u]; i < SZ(AL[u]); i++) {
      int& v = EL[AL[u][i]].v;
      int &cap = EL[AL[u][i]].cap, &flow = EL[AL[u][i]].flow;
      if (d[u] + 1 != d[v]) continue;
      if (int pushed = dfs(v, t, min(f, cap - flow))) {
        flow += pushed;
        int& rflow = EL[AL[u][i] ^ 1].flow;
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  int dinic(int s, int t) {
    int mf = 0;
    while (bfs(s, t)) {
      last.assign(V, 0);
      while (int f = dfs(s, t)) mf += f;
    }
    return mf;
  }
};

void solve(vector<string>& s) {
  if (!SZ(s)) return;
  int n = 0;
  max_flow g(26 + 10 + 2);
  fore(i, 1, 11) g.add_edge(i + 26, 37, 1);
  fore(i, 0, SZ(s)) {
    n += s[i][1] - '0';
    g.add_edge(0, s[i][0] - 'A' + 1, s[i][1] - '0');
    fore(j, 3, SZ(s[i]) - 1) {
      g.add_edge(s[i][0] - 'A' + 1, s[i][j] - '0' + 27, 1);
    }
  }
  if (g.dinic(0, 37) < n) {
    puts("!");
    return;
  }
  string ans = "__________";
  fore(k, 0, SZ(s)) {
    int u = s[k][0] - 'A' + 1;
    for (int& i : g.AL[u]) {
      int v = g.EL[i].v;
      int flow = g.EL[i].flow;
      if (flow > 0) ans[v - 27] = s[k][0];
    }
  }
  for (char c : ans) printf("%c", c);
  puts("");
}

int main() {
  char c[1024];
  vector<string> s;
  while (scanf("%[^\n]s)", c) != EOF) {
    getchar();
    string aux(c);
    if (SZ(s) && aux == s.back()) {
      solve(s);
      s.clear();
    } else
      s.push_back(aux);
  }
  solve(s);
  return 0;
}
