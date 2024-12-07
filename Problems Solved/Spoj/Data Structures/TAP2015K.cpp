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

const int INF = 1e9 + 10;

struct STree {
  vector<int> st;
  int n;
  STree(int _n = 0) {
    n = _n;
    st = vector<int>(_n * 2, -INF);
  }
  void upd(int p, int v) {
    for (st[p += n] = v; p >>= 1;) st[p] = max(st[p << 1], st[(p << 1) | 1]);
  }
  int query(int l, int r) {
    int resl = -INF, resr = -INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = max(resl, st[l++]);
      if (r & 1) resr = max(st[--r], resr);
    }
    return max(resl, resr);
  }
};

int n;

void solve() {
  int q;
  cin >> q;
  int s[n];
  forn(i, n) { cin >> s[i]; }
  map<int, set<int>> a;
  forn(i, n) a[s[i]].insert(i + 1);
  for (auto it = a.begin(); it != a.end(); it++) it->snd.insert(0);

  STree segtree(n);

  forn(i, n) { segtree.upd(i, *prev(a[s[i]].find(i + 1))); }

  while (q--) {
    char c;
    cin >> c;
    if (c == 'C') {
      int k, val;
      cin >> k >> val;

      auto it1 = a[s[k - 1]].find(k);
      it1 = next(it1);
      if (it1 != a[s[k - 1]].end()) {
        int pos = *it1;
        segtree.upd(pos - 1, *prev(prev(it1)));
      }
      a[s[k - 1]].erase(k);
      s[k - 1] = val;

      a[val].insert(k);
      if (len(a[val]) == 1) a[val].insert(0);

      auto it2 = a[val].find(k);

      it2 = next(it2);
      if (it2 != a[val].end()) {
        int pos = *it2;
        segtree.upd(pos - 1, k);
      }
      it2 = prev(it2);
      segtree.upd(k - 1, *prev(it2));
    } else {
      int k;
      cin >> k;
      cout << k - segtree.query(0, k) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    solve();
  }
  return 0;
}
