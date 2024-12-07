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

const int INF = 1e9;

const int MAXN = 2e5 + 10;

#define op max
#define NEUT -INF

struct STree {
  vector<int> st;
  int n;
  STree(int _n) {
    n = _n;
    st = vector<int>(n * 2, NEUT);
  }
  void upd(int p, int v) {
    for (st[p += n] = v; p >>= 1;) st[p] = op(st[p << 1], st[(p << 1) | 1]);
  }
  int query(int l, int r) {
    int resl = NEUT, resr = NEUT;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, st[l++]);
      if (r & 1) resr = op(st[--r], resr);
    }
    return op(resl, resr);
  }
};

typedef long long ll;

int n;
vector<int> x, dp;

void compress() {
  vector<int> v = x;
  sort(all(v));
  v.resize(distance(v.begin(), unique(all(v))));
  forn(i, n) { x[i] = (int)distance(v.begin(), lower_bound(all(v), x[i])); }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  x = vector<int>(n);
  forn(i, n) cin >> x[i];
  compress();
  dp = vector<int>(n + 1, 0);
  STree st(MAXN);
  fore(i, 1, n + 1) {
    dp[i] = max(1, 1 + st.query(0, x[i - 1]));
    st.upd(x[i - 1], dp[i]);
  }
  int ans = dp[0];
  fore(i, 1, n + 1) ans = max(ans, dp[i]);
  cout << ans << "\n";
  return 0;
}
