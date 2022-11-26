#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<int> vi;

#define sz(x) (int)x.size()

class SegmentTree {
 private:
  int n;
  v64 st, lazy, A;

  int l(int p) { return p * 2; }
  int r(int p) { return p * 2 + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L];
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m + 1, R);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
      st[p] = lazy[p] * (R - L + 1);
      if (L != R) lazy[l(p)] = lazy[r(p)] = lazy[p];

      lazy[p] = -1;
    }
  }

  ll rsq(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (L > j || R < i) return 0;
    if (L >= i && R <= j) return st[p];

    int m = (L + R) / 2;
    return rsq(l(p), L, m, i, j) + rsq(r(p), m + 1, R, i, j);
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
      st[p] = st[l(p)] + st[r(p)];
    }
  }

 public:
  SegmentTree(int m) : n(m), st(4 * n), lazy(4 * n, -1) {}
  SegmentTree(const v64& initA) : SegmentTree(sz(initA)) {
    A = initA;
    build(1, 0, n - 1);
  }
  ll rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }
  void update(int i, int j, int v) { update(1, 0, n - 1, i, j, v); }
};

int main() {
  v64 A = {18, 17, 13, 19, 15, 11, 20, 99};  // make n a power of 2
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("              A is {18,17,13,19,15,11,20,99}\n");
  printf("RSQ(1, 3) = %lld\n", st.rsq(1, 3));
  printf("RSQ(4, 7) = %lld\n", st.rsq(4, 7));
  printf("RSQ(3, 4) = %lld\n", st.rsq(3, 4));

  st.update(5, 5, 77);
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {18,17,13,19,15,77,20,99}\n");
  printf("RSQ(1, 3) = %lld\n", st.rsq(1, 3));
  printf("RSQ(4, 7) = %lld\n", st.rsq(4, 7));
  printf("RSQ(3, 4) = %lld\n", st.rsq(3, 4));

  st.update(0, 3, 30);  // update A[0..3] to 30
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30,30,15,77,20,99}\n");
  printf("RSQ(1, 3) = %lld\n", st.rsq(1, 3));
  printf("RSQ(4, 7) = %lld\n", st.rsq(4, 7));
  printf("RSQ(3, 4) = %lld\n", st.rsq(3, 4));

  st.update(3, 3, 7);  // update A[3] to 7
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30, 7,15,77,20,99}\n");
  printf("RSQ(1, 3) = %lld\n", st.rsq(1, 3));
  printf("RSQ(4, 7) = %lld\n", st.rsq(4, 7));
  printf("RSQ(3, 4) = %lld\n", st.rsq(3, 4));

  return 0;
}
