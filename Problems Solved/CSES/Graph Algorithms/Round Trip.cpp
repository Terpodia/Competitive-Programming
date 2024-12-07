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

const int MAXN = 1e5 + 10;

vector<int> g[MAXN];
bool vis[MAXN];
int p[MAXN];
int cycle, ls;

void dfs(int u) {
  if (cycle != -1) return;
  vis[u] = true;
  for (int v : g[u])
    if (v != p[u]) {
      if (cycle != -1) return;

      if (!vis[v]) {
        p[v] = u;
        dfs(v);
      } else {
        ls = u;
        cycle = v;
        return;
      }
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cycle = -1;
  memset(p, -1, sizeof(p));
  int n, m;
  cin >> n >> m;
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  forn(i, n) {
    if (!vis[i]) {
      dfs(i);
      if (cycle != -1) {
        vector<int> ans;
        ans.pb(cycle);
        while (ls != cycle && ls != -1) {
          ans.pb(ls);
          ls = p[ls];
        }
        ans.pb(cycle);
        reverse(all(ans));
        cout << len(ans) << "\n";
        for (int i : ans) cout << i + 1 << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
