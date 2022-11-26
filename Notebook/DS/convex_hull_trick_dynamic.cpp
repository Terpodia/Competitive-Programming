// Minimum queries, the lines are added in descending order of slope (m)
// The lines are of the form y = mx + b, and x must be non negative

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

struct Line {
  bool type;
  ll m, b;
  ld p;
  bool operator<(const Line& l) const {
    if (!type || !l.type) return p < l.p;
    return m > l.m;  // m < l.p for maximum queries
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
    if (has_next(it) && it->b >= next(it)->b)
      return true;  // it->b <= next(it)->b for maximum queries
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
      if (b >= it->b) return;  // b <= next(it)->b for maximum queries
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

int main() { return 0; }
