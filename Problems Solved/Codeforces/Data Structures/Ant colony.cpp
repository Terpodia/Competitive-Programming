#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9 + 7;

struct Vertex {
  int gcd, lo, cnt;
  void merge(Vertex L, Vertex R) {
    gcd = __gcd(L.gcd, R.gcd);
    if (L.lo < R.lo)
      lo = L.lo, cnt = L.cnt;
    else if (R.lo < L.lo)
      lo = R.lo, cnt = R.cnt;
    else
      lo = L.lo, cnt = L.cnt + R.cnt;
  }
};

class SegmentTree {
 private:
  int n;
  vector<Vertex> st;
  vector<int> a;

  int l(int v) { return v * 2; }
  int r(int v) { return v * 2 + 1; }

  void build(int L, int R, int v) {
    if (R - L == 1)
      st[v] = {a[L], a[L], 1};
    else {
      int m = (L + R) / 2;
      build(L, m, l(v));
      build(m, R, r(v));
      st[v].merge(st[l(v)], st[r(v)]);
    }
  }

  Vertex query(int L, int R, int v, int i, int j) {
    if (L >= i && R <= j) return st[v];
    if (L >= j || R <= i) return {0, INF, 0};
    int m = (L + R) / 2;
    Vertex ret;
    ret.merge(query(L, m, l(v), i, j), query(m, R, r(v), i, j));
    return ret;
  }

 public:
  SegmentTree() {}
  SegmentTree(int m) : n(m), st(4 * m) {}
  SegmentTree(vector<int>& v) : SegmentTree(sz(v)) {
    a = v;
    build(0, n, 1);
  }
  Vertex query(int i, int j) { return query(0, n, 1, i, j); }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  int t;
  cin >> t;
  SegmentTree st(s);

  while (t--) {
    int l, r;
    cin >> l >> r;
    l--;
    Vertex ret = st.query(l, r);
    r--;
    if (ret.gcd == ret.lo)
      cout << r - l + 1 - ret.cnt << "\n";
    else
      cout << r - l + 1 << "\n";
  }

  return 0;
}
