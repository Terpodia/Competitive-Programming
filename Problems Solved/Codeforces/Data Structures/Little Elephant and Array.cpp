//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct vertex {
  int sum;
  vertex() { sum = 0; }
  vertex(int _sum) : sum(_sum) {}
};

vertex merge(vertex a, vertex b) { return a.sum + b.sum; }

class SegmentTree {
 private:
  int n;
  vector<vertex> st;

  void update(int p, int l, int r, int& i, vertex& x) {
    if (r - l == 1)
      st[p] = x;
    else {
      int m = (l + r) / 2;
      if (i < m)
        update(2 * p, l, m, i, x);
      else
        update(2 * p + 1, m, r, i, x);
      st[p] = merge(st[2 * p], st[2 * p + 1]);
    }
  }
  vertex calc(int p, int l, int r, int& i, int& j) {
    if (l >= i && r <= j) return st[p];
    vertex ret(0);
    if (l >= j || r <= i) return ret;
    int m = (l + r) / 2;
    ret = merge(calc(2 * p, l, m, i, j), calc(2 * p + 1, m, r, i, j));
    return ret;
  }

 public:
  SegmentTree() {}
  SegmentTree(int _n) : n(_n) { st.resize(4 * n); }
  void update(int i, int x) {
    vertex y(x);
    update(1, 0, n, i, y);
  }
  vertex calc(int i, int j) { return calc(1, 0, n, i, j); }
};

struct query {
  int i, l, r;
  bool operator<(const query& q) const {
    if (l != q.l) return l < q.l;
    return r < q.r;
  }
};

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  rep(i, 0, n) scanf("%d", &a[i]);
  vector<query> b(q);
  rep(i, 0, q) {
    scanf("%d%d", &b[i].l, &b[i].r);
    b[i].i = i;
    b[i].l--;
  }
  sort(b.begin(), b.end());

  map<int, deque<int>> mp;
  rep(i, 0, n) mp[a[i]].push_back(i);

  SegmentTree st(n);
  rep(i, 0, n) st.update(i, 0);
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int z = -1, w = -1;
    if (sz(it->snd) >= it->fst) {
      z = it->snd[it->fst - 1];
      if (sz(it->snd) > it->fst) w = it->snd[it->fst];
    }
    if (z != -1) st.update(z, 1);
    if (w != -1) st.update(w, -1);
  }

  vector<int> ans(q, 0);
  int j = 0;

  rep(i, 0, n) {
    while (j < q && b[j].l == i) {
      ans[b[j].i] = st.calc(b[j].l, b[j].r).sum;
      j++;
    }

    if (sz(mp[a[i]]) >= a[i]) st.update(mp[a[i]][a[i] - 1], 0);
    mp[a[i]].pop_front();

    int z = -1, w = -1;
    if (sz(mp[a[i]]) >= a[i]) {
      z = mp[a[i]][a[i] - 1];
      if (sz(mp[a[i]]) > a[i]) w = mp[a[i]][a[i]];
    }
    if (z != -1) st.update(z, 1);
    if (w != -1) st.update(w, -1);
  }

  rep(i, 0, q) printf("%d\n", ans[i]);

  return 0;
}

