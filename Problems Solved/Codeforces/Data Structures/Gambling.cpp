#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n....................................................\n";

typedef __uint128_t u128;
typedef long long ll;

const ll INF = 1e18;

struct vertex {
  ll sum, max_sum, max_pref, max_suff;

  void merge(ll a) {
    sum = a;
    max_sum = max_pref = max_suff = max(a, (ll)0);
  }

  void merge(vertex a, vertex b) {
    sum = a.sum + b.sum;

    max_sum = max(a.max_sum, b.max_sum);
    max_sum = max(max_sum, a.max_suff + b.max_pref);

    max_pref = max(a.max_pref, a.sum + b.max_pref);
    max_suff = max(b.max_suff, b.sum + a.max_suff);
  }
};

class SegmentTree {
 private:
  vector<vertex> st;
  int n;
  vector<ll> a;

  int l(int p) { return p * 2; }
  int r(int p) { return p * 2 + 1; }

  void build(int p, int lx, int rx) {
    if (rx - lx == 1)
      st[p].merge(a[lx]);

    else {
      int m = (lx + rx) / 2;
      build(l(p), lx, m);
      build(r(p), m, rx);
      st[p].merge(st[l(p)], st[r(p)]);
    }
  }

  void update(int p, int lx, int rx, int i, int j) {
    if (rx - lx == 1)
      st[p].merge(j);
    else {
      int m = (lx + rx) / 2;
      if (i < m)
        update(l(p), lx, m, i, j);
      else
        update(r(p), m, rx, i, j);
      st[p].merge(st[l(p)], st[r(p)]);
    }
  }

  vertex query(int p, int lx, int rx, int i, int j) {
    if (lx >= i && rx <= j) return st[p];
    if (rx <= i || lx >= j) return {-INF, 0, 0, 0};
    int m = (lx + rx) / 2;
    vertex u = query(l(p), lx, m, i, j);
    vertex v = query(r(p), m, rx, i, j);
    vertex ret;
    ret.merge(u, v);
    return ret;
  }

 public:
  SegmentTree() {}

  SegmentTree(vector<ll>& v) {
    a = v;
    n = sz(a);
    st.resize(n * 4);
    build(1, 0, n);
  }

  void update(int i, int j) { update(1, 0, n, i, j); }

  ll query(int i, int j) { return query(1, 0, n, i, j).max_sum; }
};

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<ll> x(n);
    rep(i, 0, n) scanf("%lld", &x[i]);

    map<int, vector<int>> mp;
    rep(i, 0, n) mp[x[i]].pb(i);

    SegmentTree st(x);
    rep(i, 0, n) st.update(i, -1);

    int a = 0;
    ll hi = -INF;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      rep(i, 0, sz(it->second)) st.update(it->second[i], 1);
      ll q = st.query(0, n);
      if (hi < q) hi = q, a = it->first;
      rep(i, 0, sz(it->second)) st.update(it->second[i], -1);
    }
    rep(i, 0, n) x[i] = (x[i] == a) ? 1 : -1;

    int l = 0;
    ll acc = 0;

    rep(r, 0, n) {
      acc += x[r];
      if (acc == hi) {
        printf("%d %d %d\n", a, l + 1, r + 1);
        break;
      }
      while (acc < 0) acc -= x[l++];
    }
  }
  return 0;
}
