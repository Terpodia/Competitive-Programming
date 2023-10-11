#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

struct STree {
  vector<ll> st, lazy;
  vector<int> t;
  int n;
  STree(int _n) : st(4 * _n, 0), lazy(4 * _n, 0), t(4 * _n, 0), n(_n) {}
  void build(int k, int s, int e, ll* a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) / 2;
    build(2 * k, s, m, a);
    build(2 * k + 1, m, e, a);
    st[k] = st[2 * k] + st[2 * k + 1];
  }
  void push(int k, int s, int e) {
    if (!t[k]) return;
    if (t[k] == 1)
      st[k] += lazy[k] * (e - s);
    else
      st[k] = lazy[k] * (e - s);
    if (s + 1 < e) {
      if (t[k] == 1) {
        lazy[2 * k] += lazy[k], lazy[2 * k + 1] += lazy[k];
        if (!t[2 * k]) t[2 * k] = 1;
        if (!t[2 * k + 1]) t[2 * k + 1] = 1;
      } else {
        lazy[2 * k] = lazy[k], lazy[2 * k + 1] = lazy[k];
        t[2 * k] = t[2 * k + 1] = 2;
      }
    }
    t[k] = lazy[k] = 0;
  }
  void upd(int k, int s, int e, int a, int b, ll v, int type) {
    push(k, s, e);
    if (s >= b || e <= a) return;
    if (s >= a && e <= b) {
      t[k] = type, lazy[k] += v;
      push(k, s, e);
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k, s, m, a, b, v, type);
    upd(2 * k + 1, m, e, a, b, v, type);
    st[k] = st[2 * k] + st[2 * k + 1];
  }
  ll query(int k, int s, int e, int a, int b) {
    push(k, s, e);
    if (s >= b || e <= a) return 0;
    if (s >= a && e <= b) return st[k];
    int m = (s + e) / 2;
    return query(2 * k, s, m, a, b) + query(2 * k + 1, m, e, a, b);
  }
  void build(ll* a) { build(1, 0, n, a); }
  void upd(int a, int b, ll v, int type) { upd(1, 0, n, a, b, v, type); }
  ll query(int a, int b) { return query(1, 0, n, a, b); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  ll a[n];
  fore(i, 0, n) cin >> a[i];
  STree s(n);
  s.build(a);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1 || t == 2) {
      ll v;
      cin >> v;
      s.upd(l - 1, r, v, t);
    } else
      cout << s.query(l - 1, r) << "\n";
  }
  return 0;
}
