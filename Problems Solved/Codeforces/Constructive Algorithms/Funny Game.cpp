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
  int n;
  cin >> n;
  int a[n];
  forn(i, n) cin >> a[i];

  pair<int, int> ans[n];
  UnionFind dsu(n);
  for (int i = n - 1; i >= 1; i--) {
    vector<int> v[i + 1];
    forn(j, n) v[a[j] % i].push_back(j);

    ans[i] = {-1, -1};

    forn(j, i + 1) {
      if (ans[i].fst != -1) break;
      map<int, int> m;
      for (int u : v[j]) {
        m[dsu.find(u)] = u;
      }
      if (len(m) > 1) {
        auto it = m.begin();
        ans[i].fst = it->snd;
        it++;
        ans[i].snd = it->snd;
      }
    }
    dsu.join(ans[i].fst, ans[i].snd);
    ans[i].fst++, ans[i].snd++;
  }
  cout << "YES\n";
  fore(i, 1, n) cout << ans[i].fst << " " << ans[i].snd << "\n";
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
