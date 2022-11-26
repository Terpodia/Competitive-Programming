#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;

#define LSOne(x) (x) & (-x)

const int MAXLOG = 24;

class FenwickTree {
 private:
  v64 ft;
  int m;

 public:
  void build(const v64& f) {
    m = (int)f.size() + 1;
    ft = v64(m, 0);
    for (int i = 1; i < m; i++) {
      ft[i] += f[i - 1];
      if (i + (LSOne(i)) < m) ft[i + (LSOne(i))] += ft[i];
    }
  }

  FenwickTree(int n) : m(n + 1) { ft = v64(m, 0); }

  FenwickTree(const v64& f) { build(f); }

  FenwickTree(int n, const v64& a) {
    v64 f(n + 1, 0);
    for (int i = 0; i < (int)a.size(); i++) f[a[i]]++;

    build(f);
  }

  ll rsq(int j) {
    ll sum = 0;
    for (int i = j; i > 0; i -= LSOne(i)) sum += ft[i];

    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

  void update(int j, ll v) {
    for (int i = j; i < m; i += LSOne(i)) ft[i] += v;
  }

  int select(ll k) {
    int index = 0;
    ll sum = 0;

    for (int i = MAXLOG; i >= 0; i--) {
      if (index + (1 << i) < m && sum + ft[index + (1 << i)] < k) {
        index += (1 << i);
        sum += ft[index];
      }
    }

    return index + 1;
  }
};

class RUPQ {
 private:
  FenwickTree ft;

 public:
  RUPQ(int m) : ft(FenwickTree(m)) {}

  void range_update(int i, int j, ll v) {
    ft.update(i, v);
    ft.update(j + 1, -v);
  }

  ll point_query(int i) { return ft.rsq(i); }
};

class RURQ {
 private:
  RUPQ rupq;
  FenwickTree purq;

 public:
  RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {}

  void range_update(int ui, int uj, ll v) {
    rupq.range_update(ui, uj, v);
    purq.update(ui, v * (ui - 1));
    purq.update(uj + 1, -v * uj);
  }

  ll rsq(int j) { return rupq.point_query(j) * j - purq.rsq(j); }

  ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};

int main() {
  v64 f = {0, 1, 0, 1, 2, 3, 2, 1, 1, 0};  // index 0 is always 0
  FenwickTree ft(f);
  printf("%lld\n", ft.rsq(1, 6));   // 7 => ft[6]+ft[4] = 5+2 = 7
  printf("%d\n", ft.select(7));     // index 6, rsq(1, 6) == 7, which is >= 7
  ft.update(5, 1);                  // update demo
  printf("%lld\n", ft.rsq(1, 10));  // now 12
  printf("=====\n");
  RUPQ rupq(10);
  RURQ rurq(10);
  rupq.range_update(2, 9, 7);  // indices in [2, 3, .., 9] updated by +7
  rurq.range_update(2, 9, 7);  // same as rupq above
  rupq.range_update(6, 7, 3);  // indices 6&7 are further updated by +3 (10)
  rurq.range_update(6, 7, 3);  // same as rupq above
  // idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10
  // val = -          | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0
  for (int i = 1; i <= 10; i++) printf("%d -> %lld\n", i, rupq.point_query(i));
  printf("RSQ(1, 10) = %lld\n", rurq.rsq(1, 10));  // 62
  printf("RSQ(6, 7) = %lld\n", rurq.rsq(6, 7));    // 20
  return 0;
}
