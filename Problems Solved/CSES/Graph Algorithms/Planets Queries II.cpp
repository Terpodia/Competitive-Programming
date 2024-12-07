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

const int INF = 1e9;

const int MAXN = 2e5 + 10;

int n, q, nxt[MAXN][30], in[MAXN], dist[MAXN];
bool in_cycle[MAXN], vis[MAXN], vis2[MAXN];
pair<int, int> pos[MAXN];

int dfs(int u) {
  if (vis[u]) return dist[u];
  vis[u] = true;
  int v = nxt[u][0];
  if (!in_cycle[v]) return dist[u] = 1 + dfs(v);
  return dist[u] = 1;
}

void cycle(int u, int &cur) {
  vis2[u] = true;
  pos[u] = make_pair(cur, 0);
  cur++;
  int v = nxt[u][0];
  if (!vis2[v]) cycle(v, cur);
}
void set_length(int u, int sz) {
  vis[u] = true;
  pos[u].snd = sz;
  int v = nxt[u][0];
  if (!vis[v]) set_length(v, sz);
}

void bfs() {
  forn(i, n) {
    in_cycle[i] = true;
    in[nxt[i][0]]++;
  }
  queue<int> q;
  forn(i, n) {
    if (in[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    in_cycle[u] = false;
    in[nxt[u][0]]--;
    if (in[nxt[u][0]] == 0) {
      q.push(nxt[u][0]);
    }
  }
  forn(i, n) if (!vis[i] && !in_cycle[i]) dfs(i);
  forn(i, n) {
    if (!vis[i] && in_cycle[i]) {
      int sz = 0;
      cycle(i, sz);
      set_length(i, sz);
    }
  }
}

int mv(int u, int k) {
  int ret = u;
  dfor(i, 30) {
    int a = (1 << i);
    if (k - a >= 0) ret = nxt[ret][i], k -= a;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  forn(i, n) {
    cin >> nxt[i][0];
    nxt[i][0]--;
  }
  fore(i, 1, 30) { forn(j, n) nxt[j][i] = nxt[nxt[j][i - 1]][i - 1]; }
  bfs();
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (dist[u] != 0 && dist[v] != 0) {
      if (dist[u] < dist[v])
        cout << "-1\n";
      else {
        int a = mv(u, dist[u] - dist[v]);
        if (a != v)
          cout << "-1\n";
        else
          cout << dist[u] - dist[v] << "\n";
      }
    } else if (dist[u] == 0 && dist[v] != 0)
      cout << "-1\n";
    else {
      int res = 0;
      if (dist[u] != 0) res += dist[u], u = mv(u, dist[u]);
      int r = pos[v].fst - pos[u].fst;
      if (r < 0) r += pos[u].snd;
      if (r < 0)
        cout << "-1\n";
      else {
        u = mv(u, r);
        res += r;
        if (u != v)
          cout << "-1\n";
        else
          cout << res << "\n";
      }
    }
  }
  return 0;
}
