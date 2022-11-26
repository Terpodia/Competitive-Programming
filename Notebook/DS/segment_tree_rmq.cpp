#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

typedef vector<int> vi;

const int INF = 1e9;

class SegmentTree {
 private:
  int n;
  vi A, st, lazy;

  int l(int p) { return (p * 2); }
  int r(int p) { return p * 2 + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L];
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m + 1, R);
      st[p] = min(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
      st[p] = lazy[p];
      if (L != R) lazy[l(p)] = lazy[r(p)] = lazy[p];

      lazy[p] = -1;
    }
  }

  int RMQ(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (L > j || R < i) return INF;
    if (L >= i && R <= j) return st[p];

    int m = (L + R) / 2;
    return min(RMQ(l(p), L, m, i, j), RMQ(r(p), m + 1, R, i, j));
  }

  void update(int p, int L, int R, int i, int j, int v) {
    propagate(p, L, R);
    if (L > j || R < i) return;
    if (L >= i && R <= j) {
      lazy[p] = v;
      propagate(p, L, R);
    } else {
      int m = (L + R) / 2;
      update(l(p), L, m, i, j, v);
      update(r(p), m + 1, R, i, j, v);
      st[p] = min(st[l(p)], st[r(p)]);
      // int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      // int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      // st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
    }
  }

 public:
  SegmentTree(int m) : n(m), st(4 * n), lazy(4 * n, -1) {}

  SegmentTree(const vi &initA) : SegmentTree(sz(initA)) {
    A = initA;
    build(1, 0, n - 1);
  }

  int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }

  void update(int i, int j, int v) { update(1, 0, n - 1, i, j, v); }
};

int main() {
  vi A = {18, 17, 13, 19, 15, 11, 20, 99};  // make n a power of 2
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("              A is {18,17,13,19,15,11,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));  // 13
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));  // 11
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));  // 15

  st.update(5, 5, 77);  // update A[5] to 77
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {18,17,13,19,15,77,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));  // remains 13
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));  // now 15
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));  // remains 15

  st.update(0, 3, 30);  // update A[0..3] to 30
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30,30,15,77,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));  // now 30
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));  // remains 15
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));  // remains 15

  st.update(3, 3, 7);  // update A[3] to 7
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30, 7,15,77,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));  // now 7
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));  // remains 15
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));  // now 7

  return 0;
}
