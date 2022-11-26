#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

struct SegmentTree {
  vector<int> st;  // An array that contains de information for each node

  // Constructor
  SegmentTree(int n) {
    st = vector<int>(4 * n);  // initializing array
  }

  void build(int lx, int rx, int u, vector<int>& a) {
    if (lx == rx) {
      st[u] = a[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(lx, m, u * 2, a);
    build(m + 1, rx, u * 2 + 1, a);

    st[u] = min(st[u * 2], st[u * 2 + 1]);
  }

  // Build segment tree from an array "a"
  void build(vector<int>& a) { build(0, sz(a) - 1, 1, a); }

  int calc(int l, int r, int lx, int rx, int u) {
    if (lx >= l && rx <= r) return st[u];
    if (lx > r || rx < l) return 1e9;

    int m = (lx + rx) / 2;
    return min(calc(l, r, lx, m, u * 2), calc(l, r, m + 1, rx, u * 2 + 1));
  }

  // Calc de rmq in the range [l, r]
  int calc(int l, int r) {
    return calc(l, r, 0, sz(st) / 4 - 1, 1);  // sz(st) = 4*n
  }

  void update(int val, int pos, int lx, int rx, int u) {
    if (lx == rx) {
      st[u] = val;
      return;
    }
    int m = (lx + rx) / 2;

    if (pos <= m)
      update(val, pos, lx, m, u * 2);
    else
      update(val, pos, m + 1, rx, u * 2 + 1);

    st[u] = min(st[u * 2], st[u * 2 + 1]);
  }

  // Update value in some position with some value
  void update(int val, int pos) { update(val, pos, 0, sz(st) / 4 - 1, 1); }
};

int main() {
  int n, q;
  scanf("%d%d", &n, &q);  // size of the array and number of queries
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  SegmentTree st(n);  // The segment tree
  st.build(a);        // Building the segment tree

  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 1) {  // RMQ in range [l, r] (0-indexed)
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", st.calc(l, r));  // Output
    }

    else {  // If type == 2, then update a[u] = v
      int u, v;
      scanf("%d%d", &u, &v);
      st.update(v, u);  // Updating segment tree
    }
  }

  return 0;
}
