#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct STree {
  vector<ll> sum, hi;
  int n;
  STree(int _n) : sum(4 * _n, 0), hi(4 * _n, -INF), n(_n) {}
  void eval(int k) {
    sum[k] = sum[2 * k] + sum[2 * k + 1];
    hi[k] = max(hi[2 * k], hi[2 * k + 1]);
  }
  void build(int k, int s, int e, ll *a) {
    if (s + 1 == e) {
      sum[k] = hi[k] = a[s];
      return;
    }
    int m = (s + e) / 2;
    build(2 * k, s, m, a);
    build(2 * k + 1, m, e, a);
    eval(k);
  }
  void upd(int k, int s, int e, int pos, ll v) {
    if (s + 1 == e) {
      sum[k] = hi[k] = v;
      return;
    }
    int m = (s + e) / 2;
    if (pos < m)
      upd(2 * k, s, m, pos, v);
    else
      upd(2 * k + 1, m, e, pos, v);
    eval(k);
  }
  void mod(int k, int s, int e, int a, int b, ll x) {
    if (s >= b || e <= a) return;
    if (s + 1 == e) {
      sum[k] %= x, hi[k] %= x;
      return;
    }
    int m = (s + e) / 2;
    if (hi[2 * k] >= x) mod(2 * k, s, m, a, b, x);
    if (hi[2 * k + 1] >= x) mod(2 * k + 1, m, e, a, b, x);
    eval(k);
  }
  ll query(int k, int s, int e, int a, int b) {
    if (s >= b || e <= a) return 0;
    if (s >= a && e <= b) return sum[k];
    int m = (s + e) / 2;
    return query(2 * k, s, m, a, b) + query(2 * k + 1, m, e, a, b);
  }
  void build(ll *a) { build(1, 0, n, a); }
  void upd(int pos, ll v) { upd(1, 0, n, pos, v); }
  void mod(int a, int b, ll x) { mod(1, 0, n, a, b, x); }
  ll query(int a, int b) { return query(1, 0, n, a, b); }
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  ll a[n];
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  STree s(n);
  s.build(a);
  while (m--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      printf("%lld\n", s.query(l, r));
    } else if (type == 2) {
      int l, r;
      ll x;
      scanf("%d%d%lld", &l, &r, &x);
      l--;
      s.mod(l, r, x);
    } else {
      int k;
      ll x;
      scanf("%d%lld", &k, &x);
      k--;
      s.upd(k, x);
    }
  }
  return 0;
}
