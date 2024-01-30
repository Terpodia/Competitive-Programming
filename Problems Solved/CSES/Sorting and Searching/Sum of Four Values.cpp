#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

struct tup {
  int sum, i, j;
  tup() {}
  tup(int _sum, int _i, int _j) : sum(_sum), i(_i), j(_j) {}
  bool operator<(const tup& a) const {
    if (sum != a.sum) return sum < a.sum;
    if (i != a.i) return i < a.i;
    return j < a.j;
  }
};

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);

  vector<tup> v;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      v.push_back({a[i] + a[j], i, j});
    }
  }

  sort(all(v));

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      if (a[i] + a[j] <= x) {
        int r = x - a[i] - a[j];

        auto it = lower_bound(all(v), tup(r, i + 1, j + 1));

        if (it != v.end() && it->sum == r && it->i != i && it->j != j &&
            it->i != j && it->j != i) {
          printf("%d %d %d %d\n", i + 1, j + 1, it->i + 1, it->j + 1);
          return 0;
        }

        it = lower_bound(all(v), tup(r, i + 1, -1));

        if (it != v.end() && it->sum == r && it->i != i && it->j != j &&
            it->i != j && it->j != i) {
          printf("%d %d %d %d\n", i + 1, j + 1, it->i + 1, it->j + 1);
          return 0;
        }

        it = lower_bound(all(v), tup(r, -1, j + 1));

        if (it != v.end() && it->sum == r && it->i != i && it->j != j &&
            it->i != j && it->j != i) {
          printf("%d %d %d %d\n", i + 1, j + 1, it->i + 1, it->j + 1);
          return 0;
        }

        it = lower_bound(all(v), tup(r, -1, -1));

        if (it != v.end() && it->sum == r && it->i != i && it->j != j &&
            it->i != j && it->j != i) {
          printf("%d %d %d %d\n", i + 1, j + 1, it->i + 1, it->j + 1);
          return 0;
        }
      }
  }

  puts("IMPOSSIBLE");
  return 0;
}
