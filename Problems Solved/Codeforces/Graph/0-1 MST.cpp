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

struct UnionFind {
  int n, comp;
  vector<int> uf, si, c;
  UnionFind(int n = 0) : n(n), comp(n), uf(n), si(n, 1) {
    fore(i, 0, n) uf[i] = i;
  }
  int find(int x) { return x == uf[x] ? x : find(uf[x]); }
  bool join(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (si[x] < si[y]) swap(x, y);
    si[x] += si[y];
    uf[y] = x;
    comp--;
    c.pb(y);
    return true;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> g[n];

  set<int> comp;
  comp.insert(0);
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  UnionFind dsu(n);
  fore(i, 1, n) {
    map<int, int> cnt;
    for (int v : g[i])
      if (v < i) {
        cnt[dsu.find(v)]++;
      }
    queue<int> del;
    for (int u : comp) {
      if (dsu.si[u] > cnt[u]) {
        del.push(u);
        dsu.join(u, i);
      }
    }
    while (!del.empty()) {
      comp.erase(del.front());
      del.pop();
    }
    comp.insert(dsu.find(i));
  }
  cout << len(comp) - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
