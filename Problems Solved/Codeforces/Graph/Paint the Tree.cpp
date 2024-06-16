#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

// MACROS
#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
// FOR
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
// DEBUG
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
typedef vector<int> vint;
typedef pair<int, int> pint;

const int MAXN = 2e5 + 10;

vint g[MAXN];
int n, a, b;
ll dp[2][MAXN];

ll dfs(int u, int p = -1) {
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
      dp[1][u] += dp[1][v] + 2;
    }
  dp[0][u] = dp[1][u];
  for (int v : g[u])
    if (v != p) {
      dp[0][u] = min(dp[0][u], dp[1][u] - dp[1][v] - 2 + dp[0][v] + 1);
    }
  return dp[0][u];
}

void solve() {
  vint color[2];
  color[0] = color[1] = vint(n, 0);
  queue<pint> q;

  q.push({b, 1});
  q.push({a, 0});
  color[0][a] = 1, color[1][b] = 1;

  ll dist = 0;
  int x = a;
  bool flag = false;

  while (!q.empty()) {
    auto [u, c] = q.front();
    q.pop();
    if (color[0][u] == 1 && c == 1) {
      x = u;
      break;
    }
    if (!flag && c == 0) dist++, flag = true;
    if (flag && c == 1) flag = false;
    for (int v : g[u])
      if (color[c][v] == 0) {
        color[c][v] = 1;
        q.push({v, c});
      }
  }
  forn(i, n) dp[0][i] = dp[1][i] = 0;
  cout << dist + dfs(x) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> a >> b;
    a--, b--;
    forn(i, n - 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      g[x].pb(y);
      g[y].pb(x);
    }
    solve();
    forn(i, n) g[i].clear();
  }
  return 0;
}
