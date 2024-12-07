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
  vector<int> uf, si;
  UnionFind(int _n = 0) : n(_n), comp(_n), uf(_n), si(_n, 1) {
    fore(i, 0, n) uf[i] = i;
  }
  int find(int x) { return x == uf[x] ? x : uf[x] = find(uf[x]); }
  bool join(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (si[x] < si[y]) swap(x, y);
    si[x] += si[y];
    uf[y] = x;
    comp--;
    return true;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v[11];
  forn(i, m) {
    int a, d, k;
    cin >> a >> d >> k;
    v[d].pb(make_pair(a - 1, k));
  }
  vector<int> c[11][11];
  int pos[11][n];
  fore(d, 1, 11) {
    forn(i, n) {
      c[d][i % d].pb(i);
      pos[d][i] = len(c[d][i % d]) - 1;
    }
  }
  UnionFind uf(n);
  fore(d, 1, 11) {
    sort(all(v[d]));
    vector<int> lst(d, 0);
    for (auto [a, k] : v[d]) {
      int j = pos[d][a];

      int l = max(j, lst[a % d]);
      int r = min(k, k - (lst[a % d] - j));
      if (r < 0) continue;

      fore(i, l, l + r + 1) { uf.join(a, c[d][a % d][i]); }
      lst[a % d] = l + r + 1;
    }
  }
  cout << uf.comp << "\n";
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
