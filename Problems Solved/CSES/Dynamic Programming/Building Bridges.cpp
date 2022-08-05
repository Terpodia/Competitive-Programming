// https://cses.fi/165/list/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

struct Line {
  bool type;
  ll m, b;
  ld p;
  bool operator<(const Line& l) const {
    if (!type || !l.type) return p < l.p;
    return m > l.m;
  }
};

struct LineContainer : set<Line> {
  bool has_prev(set<Line>::iterator it) { return it != begin(); }
  bool has_next(set<Line>::iterator it) {
    return it != end() && next(it) != end();
  }
  ld intersect(set<Line>::iterator i1, set<Line>::iterator i2) {
    return (ld)(i1->b - i2->b) / (ld)(i2->m - i1->m);
  }
  bool bad(set<Line>::iterator it) {
    if (has_next(it) && it->b >= next(it)->b) return true;
    return (has_prev(it) && has_next(it) &&
            intersect(prev(it), next(it)) <= intersect(prev(it), it));
  }
  void calc_x(set<Line>::iterator it) {
    if (has_prev(it)) {
      Line l = *it;
      l.p = intersect(prev(it), it);
      insert(erase(it), l);
    }
  }
  void add_line(ll m, ll b) {
    set<Line>::iterator it;

    it = lower_bound({1, m, b, 0});
    if (it != end() && it->m == m) {
      if (b >= it->b) return;
      erase(it);
    }

    it = insert({1, m, b, 0}).first;
    if (bad(it))
      erase(it);
    else {
      while (has_prev(it) && bad(prev(it))) erase(prev(it));
      while (has_next(it) && bad(next(it))) erase(next(it));
      if (has_next(it)) calc_x(next(it));
      calc_x(it);
    }
  }
  ll query(ll x) {
    assert(!empty());
    Line l = *prev(upper_bound({0, 0, 0, (ld)x}));
    return l.m * x + l.b;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  ll h[n], w[n];
  rep(i, 0, n) scanf("%lld", h + i);
  rep(i, 0, n) scanf("%lld", w + i);
  w[0] = w[n - 1] = 0;

  ll sum = 0;
  rep(i, 0, n) sum += w[i];

  ll dp[n];
  dp[0] = 0;
  LineContainer CHT;

  rep(i, 1, n) {
    CHT.add_line(-2 * h[i - 1], h[i - 1] * h[i - 1] - w[i - 1] + dp[i - 1]);
    dp[i] = CHT.query(h[i]) + h[i] * h[i];
  }
  printf("%lld\n", dp[n - 1] + sum);
  return 0;
}

