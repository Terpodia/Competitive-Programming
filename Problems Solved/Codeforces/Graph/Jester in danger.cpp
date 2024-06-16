#pragma GCC optimize("O3,unroll-loops")

#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
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
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int MAXN = 1e5 + 10, INF = 1e9;

vector<int> g[MAXN], g_in[MAXN], g_out[MAXN];
int dist[MAXN], cnt[MAXN], in[MAXN], out[MAXN];
bool vis[MAXN], alive[MAXN];

bool broken;
int res;

void propagate(int u) {
  cnt[dist[u]]--;
  alive[u] = false;
  if (cnt[dist[u]] == 1)
    res++;
  else if (cnt[dist[u]] == 0) {
    broken = true;
    return;
  }
  for (int v : g_out[u])
    if (alive[v]) {
      in[v]--;
      if (in[v] == 0) propagate(v);
    }
  for (int v : g_in[u])
    if (alive[v]) {
      out[v]--;
      if (out[v] == 0) propagate(v);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  forn(i, n) dist[i] = INF;
  memset(vis, 0, sizeof(vis));

  dist[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u])
      if (!vis[v]) {
        vis[v] = true;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  }
  memset(vis, false, sizeof(vis));
  q.push(n - 1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    alive[u] = true, cnt[dist[u]]++;
    for (int v : g[u])
      if (dist[v] + 1 == dist[u]) {
        in[u]++, out[v]++;
        g_out[v].pb(u);
        g_in[u].pb(v);

        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
  }
  for (int i = 1; i < n - 1; i++) {
    if (alive[i] && cnt[dist[i]] == 1) res++;
  }

  cout << res << " ";
  while (k--) {
    int u;
    cin >> u;
    u--;
    if (alive[u]) propagate(u);

    if (broken)
      cout << "-1 ";
    else
      cout << res << " ";
  }
  cout << "\n";
  return 0;
}
