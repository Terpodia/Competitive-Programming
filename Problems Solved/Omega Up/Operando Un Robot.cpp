#include <iostream>
#include <vector>
using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n...............................................\n";

typedef long long ll;

void rotate90(ll& x, ll& y) {
  swap(x, y);
  x *= -1;
}

struct vertex {
  ll x, y, dir;

  void merge(int t, ll d) {
    if (t == 1)
      x = d, y = 0, dir = 0;
    else
      x = 0, y = 0, dir = d;
  }
  void merge(vertex l, vertex r) {
    rep(i, 0, l.dir) rotate90(r.x, r.y);

    dir = (l.dir + r.dir) % 4;
    x = l.x + r.x, y = l.y + r.y;
  }
};

class SegmentTree {
 private:
  int n;
  vector<vertex> st;

  int l(int p) { return 2 * p; }
  int r(int p) { return 2 * p + 1; }

  void update(int p, int lx, int rx, int i, int t, ll val) {
    if (rx - lx == 1)
      st[p].merge(t, val);
    else {
      int m = (lx + rx) / 2;
      if (i < m)
        update(l(p), lx, m, i, t, val);
      else
        update(r(p), m, rx, i, t, val);

      st[p].merge(st[l(p)], st[r(p)]);
    }
  }

  vertex query(int p, int lx, int rx, int i, int j) {
    if (lx >= i && rx <= j) return st[p];
    vertex ret;
    if (lx >= j || rx <= i) {
      ret.x = ret.y = ret.dir = 0;
      return ret;
    }
    int m = (lx + rx) / 2;
    ret.merge(query(l(p), lx, m, i, j), query(r(p), m, rx, i, j));
    return ret;
  }

 public:
  SegmentTree(int m) {
    n = m;
    st.resize(n * 4);
    rep(i, 0, n * 4) st[i] = {0, 0, 0};
  }

  void update(int i, int t, ll val) { update(1, 0, n, i, t, val); }

  vertex query(int i, int j) { return query(1, 0, n, i, j); }
};

int main() {
  int n;
  scanf("%d", &n);
  SegmentTree st(n);

  rep(i, 0, n) {
    int t;
    ll d;
    scanf("%d%lld", &t, &d);
    st.update(i, t, d);
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int tq;
    scanf("%d", &tq);
    if (tq == 1) {
      int L, R;
      scanf("%d%d", &L, &R);
      vertex ans = st.query(L, R + 1);
      printf("%lld %lld %lld\n", ans.x, ans.y, ans.dir);
    }

    else {
      int i, t;
      ll val;
      scanf("%d%d%lld", &i, &t, &val);
      st.update(i, t, val);
    }
  }
  return 0;
}
