#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

class SegmentTree {
 private:
  int n;
  vector<int> a, st, lazy;

  int l(int p) { return p * 2; }
  int r(int p) { return p * 2 + 1; }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
      if (lazy[p] == -2) {
        st[p] = (R - L + 1) - st[p];
        if (L != R) {
          if (lazy[l(p)] == -1)
            lazy[l(p)] = lazy[p];
          else if (lazy[l(p)] == 1)
            lazy[l(p)] = 0;
          else if (lazy[l(p)] == 0)
            lazy[l(p)] = 1;
          else
            lazy[l(p)] = -1;

          if (lazy[r(p)] == -1)
            lazy[r(p)] = lazy[p];
          else if (lazy[r(p)] == 1)
            lazy[r(p)] = 0;
          else if (lazy[r(p)] == 0)
            lazy[r(p)] = 1;
          else
            lazy[r(p)] = -1;
        }
      } else {
        st[p] = (R - L + 1) * lazy[p];
        if (L != R) lazy[l(p)] = lazy[r(p)] = lazy[p];
      }

      lazy[p] = -1;
    }
  }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = a[L];
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m + 1, R);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void setValue(int p, int L, int R, int i, int j, int val) {
    propagate(p, L, R);

    if (L >= i && R <= j) {
      lazy[p] = val;
      propagate(p, L, R);
    }

    else if (L > j || R < i)
      return;

    else {
      int m = (L + R) / 2;
      setValue(l(p), L, m, i, j, val);
      setValue(r(p), m + 1, R, i, j, val);

      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void inverse(int p, int L, int R, int i, int j) {
    propagate(p, L, R);

    if (L >= i && R <= j) {
      lazy[p] = -2;
      propagate(p, L, R);
    }

    else if (L > j || R < i)
      return;

    else {
      int m = (L + R) / 2;
      inverse(l(p), L, m, i, j);
      inverse(r(p), m + 1, R, i, j);

      st[p] = st[l(p)] + st[r(p)];
    }
  }

  int rsq(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (L >= i && R <= j) return st[p];
    if (L > j || R < i) return 0;

    int m = (L + R) / 2;
    return rsq(l(p), L, m, i, j) + rsq(r(p), m + 1, R, i, j);
  }

 public:
  SegmentTree(int m) : n(m), st(4 * n, 0), lazy(4 * n, -1) {}

  SegmentTree(vector<int>& v) : SegmentTree((int)v.size()) {
    a = v;
    build(1, 0, n - 1);
  }

  void setValue(int i, int j, int val) { setValue(1, 0, n - 1, i, j, val); }

  void inverse(int i, int j) { inverse(1, 0, n - 1, i, j); }

  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }
};

vector<int> v, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int TC;
  cin >> TC;
  FOR(_, 1, TC + 1) {
    int M;
    cin >> M;
    FOR(i, 0, M) {
      int T;
      cin >> T;
      string S;
      cin >> S;

      FOR(j, 0, T) for (char c : S) v.push_back(c - '0');
    }

    SegmentTree st(v);

    int Q;
    cin >> Q;

    while (Q--) {
      char c;
      int a, b;
      cin >> c >> a >> b;

      if (c == 'F')
        st.setValue(a, b, 1);
      else if (c == 'E')
        st.setValue(a, b, 0);
      else if (c == 'I')
        st.inverse(a, b);
      else
        ans.push_back(st.rsq(a, b));
    }

    cout << "Case " << _ << ":\n";

    FOR(i, 0, ans.size())
    cout << "Q" << i + 1 << ": " << ans[i] << "\n";

    v.clear();
    ans.clear();
  }

  return 0;
}
