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

const int MAXN = 3e5 + 10;

int n, parent[MAXN], p[MAXN], pos[MAXN], sz[MAXN];
vector<int> g[MAXN];

void dfs(int u) {
  sz[u] = 1;
  for (int v : g[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}
void solve() {
  int cnt = 0, q;
  cin >> n >> q;
  parent[0] = -1;
  forn(i, n - 1) {
    cin >> parent[i + 1];
    parent[i + 1]--;
    g[parent[i + 1]].pb(i + 1);
  }
  forn(i, n) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }
  dfs(0);
  multiset<int> s[n];
  vector<bool> ok(n, false);
  forn(i, n - 1) {
    s[parent[i + 1]].insert(pos[i + 1]);
    s[parent[i + 1]].insert(pos[i + 1] + sz[i + 1] - 1);
  }
  for (int u = 0; u < n; u++) {
    if (!len(s[u])) {
      ok[u] = true;
      cnt++;
      continue;
    }
    int l = pos[u] + 1, r = pos[u] + sz[u] - 1;
    int lo = *s[u].begin(), hi = *prev(s[u].end());
    if (lo >= l && hi <= r) cnt++, ok[u] = true;
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    swap(pos[p[x]], pos[p[y]]);
    swap(p[x], p[y]);
    int u = p[x], v = p[y];

    if (ok[u]) ok[u] = false, cnt--;
    if (!len(s[u]))
      ok[u] = true, cnt++;
    else {
      int l = pos[u] + 1, r = pos[u] + sz[u] - 1;
      int lo = *s[u].begin(), hi = *prev(s[u].end());
      if (lo >= l && hi <= r) cnt++, ok[u] = true;
    }
    if (parent[u] != -1) {
      if (s[parent[u]].find(pos[v]) != s[parent[u]].end())
        s[parent[u]].erase(s[parent[u]].find(pos[v]));
      if (s[parent[u]].find(pos[v] + sz[u] - 1) != s[parent[u]].end())
        s[parent[u]].erase(s[parent[u]].find(pos[v] + sz[u] - 1));
      s[parent[u]].insert(pos[u]);
      s[parent[u]].insert(pos[u] + sz[u] - 1);

      if (ok[parent[u]]) ok[parent[u]] = false, cnt--;

      int l = pos[parent[u]] + 1, r = pos[parent[u]] + sz[parent[u]] - 1;
      int lo = *s[parent[u]].begin(), hi = *prev(s[parent[u]].end());
      if (lo >= l && hi <= r) cnt++, ok[parent[u]] = true;
    }
    swap(u, v);
    if (ok[u]) ok[u] = false, cnt--;
    if (!len(s[u]))
      ok[u] = true, cnt++;
    else {
      int l = pos[u] + 1, r = pos[u] + sz[u] - 1;
      int lo = *s[u].begin(), hi = *prev(s[u].end());
      if (lo >= l && hi <= r) cnt++, ok[u] = true;
    }
    if (parent[u] != -1) {
      if (s[parent[u]].find(pos[v]) != s[parent[u]].end())
        s[parent[u]].erase(s[parent[u]].find(pos[v]));
      if (s[parent[u]].find(pos[v] + sz[u] - 1) != s[parent[u]].end())
        s[parent[u]].erase(s[parent[u]].find(pos[v] + sz[u] - 1));
      s[parent[u]].insert(pos[u]);
      s[parent[u]].insert(pos[u] + sz[u] - 1);

      if (ok[parent[u]]) ok[parent[u]] = false, cnt--;

      int l = pos[parent[u]] + 1, r = pos[parent[u]] + sz[parent[u]] - 1;
      int lo = *s[parent[u]].begin(), hi = *prev(s[parent[u]].end());
      if (lo >= l && hi <= r) cnt++, ok[parent[u]] = true;
    }
    if (cnt == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  forn(i, n) g[i].clear();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
