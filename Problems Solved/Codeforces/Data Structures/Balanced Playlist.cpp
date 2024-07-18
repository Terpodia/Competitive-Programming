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

#define op min
#define NEUT INF

struct STree {
  vector<int> st;
  int n;
  STree(int _n) {
    n = _n;
    st = vector<int>(n * 2, NEUT);
  }
  STree(int _n, vector<int> &a) {
    n = _n;
    st = vector<int>(n * 2, NEUT);
    fore(i, 0, n) st[n + i] = a[i];
    build();
  }
  void build() {
    for (int i = n - 1; i > 0; i--) st[i] = op(st[i << 1], st[(i << 1) | 1]);
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  forn(i, n) cin >> a[i];
  fore(i, n, 2 * n) a[i] = a[i - n];

  vector<int> s;
  vector<int> pm(2 * n, -1);
  forn(i, 2 * n) {
    while (len(s) && a[s.back()] < a[i]) {
      pm[s.back()] = i;
      s.pop_back();
    }
    s.pb(i);
  }

  vector<int> ans(n, -1);

  STree st(2 * n, a);

  vector<pair<int, int>> v;
  forn(i, n) v.push_back({a[i], i});
  sort(all(v));

  dfor(_, n) {
    int i = v[_].snd;
    int l = i, r = 2 * n;
    while (r > l) {
      int mid = l + (r - l) / 2;
      if (mid == 2 * n)
        r = mid;
      else if (st.query(i, mid + 1) < (a[i] + 1) / 2)
        r = mid;
      else
        l = mid + 1;
    }
    if (pm[i] == -1 || pm[i] > r) {
      if (r == 2 * n)
        ans[i] = -1;
      else
        ans[i] = r - i;
    } else {
      int j = pm[i];
      if (j >= n) j -= n;
      if (ans[j] == -1)
        ans[i] = -1;
      else
        ans[i] = ans[j] + pm[i] - i;
    }
  }
  forn(i, n) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
