#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
typedef long long ll;

struct Node {
  ll sum = 0, cnt = 0, lazy = 0;
};
struct STree {
  vector<Node> st;
  int n;
  STree(int _n) : st(4 * _n), n(_n) {}
  void build(int k, int s, int e, ll *a) {
    if (s + 1 == e) {
      st[k].sum = a[s];
      return;
    }
    int m = (s + e) / 2;
    build(2 * k, s, m, a);
    build(2 * k + 1, m, e, a);
    st[k].sum = st[2 * k].sum + st[2 * k + 1].sum;
  }
  void push(int k, int s, int e) {
    if (!st[k].cnt) return;
    st[k].sum += st[k].lazy * ((ll)e - s) +
                 st[k].cnt * ((((ll)e - s) * ((ll)e - s - 1)) / 2);
    if (s + 1 < e) {
      int m = (s + e) / 2;
      st[2 * k].cnt += st[k].cnt, st[2 * k + 1].cnt += st[k].cnt;
      st[2 * k].lazy += st[k].lazy;
      st[2 * k + 1].lazy += st[k].lazy + ((ll)m - s) * st[k].cnt;
    }
    st[k].lazy = st[k].cnt = 0;
  }
  void upd(int k, int s, int e, int a, int b) {
    push(k, s, e);
    if (s >= b || e <= a) return;
    if (s >= a && e <= b) {
      st[k].lazy += (ll)s - a + 1, st[k].cnt++;
      push(k, s, e);
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k, s, m, a, b);
    upd(2 * k + 1, m, e, a, b);
    st[k].sum = st[2 * k].sum + st[2 * k + 1].sum;
  }
  ll query(int k, int s, int e, int a, int b) {
    push(k, s, e);
    if (s >= b || e <= a) return 0;
    if (s >= a && e <= b) return st[k].sum;
    int m = (s + e) / 2;
    return query(2 * k, s, m, a, b) + query(2 * k + 1, m, e, a, b);
  }
  void build(ll *a) { build(1, 0, n, a); }
  void upd(int a, int b) { upd(1, 0, n, a, b); }
  ll query(int a, int b) { return query(1, 0, n, a, b); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  ll t[n];
  fore(i, 0, n) cin >> t[i];
  STree s(n);
  s.build(t);
  while (q--) {
    int k, l, r;
    cin >> k >> l >> r;
    l--;
    if (k == 1)
      s.upd(l, r);
    else
      cout << s.query(l, r) << "\n";
  }
  return 0;
}
