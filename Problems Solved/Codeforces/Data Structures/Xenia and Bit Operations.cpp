#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

struct Vertex {
  int val, h;
  void merge(Vertex& L, Vertex& R) {
    h = L.h + 1;
    if (h % 2 == 1)
      val = L.val | R.val;
    else
      val = L.val ^ R.val;
  }
};

class SegmentTree {
 private:
  int n;
  vector<Vertex> st;
  vector<int> a;

  int l(int v) { return 2 * v; }
  int r(int v) { return 2 * v + 1; }

  void build(int L, int R, int v) {
    if (R - L == 1)
      st[v] = {a[L], 0};
    else {
      int m = (L + R) / 2;
      build(L, m, l(v));
      build(m, R, r(v));
      st[v].merge(st[l(v)], st[r(v)]);
    }
  }

  void update(int L, int R, int v, int p, int b) {
    if (R - L == 1)
      st[v].val = b;
    else {
      int m = (L + R) / 2;
      if (p < m)
        update(L, m, l(v), p, b);
      else
        update(m, R, r(v), p, b);
      st[v].merge(st[l(v)], st[r(v)]);
    }
  }

 public:
  SegmentTree() {}
  SegmentTree(int m) : n(m), st(4 * m) {}
  SegmentTree(vector<int>& v) : SegmentTree(sz(v)) {
    a = v;
    build(0, n, 1);
  }
  void update(int p, int b) { update(0, n, 1, p, b); }
  Vertex getVertex(int v) { return st[v]; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) cin >> a[i];

  SegmentTree st(a);

  while (m--) {
    int p, b;
    cin >> p >> b;
    p--;
    st.update(p, b);
    cout << st.getVertex(1).val << "\n";
  }

  return 0;
}
