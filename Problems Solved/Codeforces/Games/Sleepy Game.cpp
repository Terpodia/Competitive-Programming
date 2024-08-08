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

const int MAXN = 1e5 + 10;

vector<int> g[MAXN];

int p[MAXN][2];
int s;

int color[MAXN];

void dfs(int u, int turn) {
  for (int v : g[u])
    if (p[v][1 - turn] == -1 && (1 - turn == 1 || v != s)) {
      p[v][1 - turn] = u;
      dfs(v, 1 - turn);
    }
}

bool can;

void cycle(int u) {
  color[u] = 1;
  for (int v : g[u]) {
    if (color[v] == 0) cycle(v);
    if (color[v] == 1) can = true;
  }
  color[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  forn(i, n) {
    int c;
    cin >> c;
    forn(j, c) {
      int v;
      cin >> v;
      v--;
      g[i].push_back(v);
    }
  }
  cin >> s;
  s--;

  memset(p, -1, sizeof(p));

  dfs(s, 0);

  for (int i = 0; i < n; i++) {
    if (p[i][1] != -1 && len(g[i]) == 0) {
      cout << "Win\n";
      vector<int> path;

      int turn = 1, cur = i;
      while (p[cur][turn] != -1) {
        path.push_back(cur);
        cur = p[cur][turn];
        turn = 1 - turn;
      }
      path.push_back(s);

      reverse(all(path));
      for (int u : path) cout << u + 1 << " ";
      cout << "\n";
      return 0;
    }
  }

  cycle(s);
  if (can) {
    cout << "Draw\n";
    return 0;
  }
  cout << "Lose\n";
  return 0;
}
