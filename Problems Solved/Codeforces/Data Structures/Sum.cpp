#include <stdio.h>

#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long ll;

struct seg_tree {
  vector<long long> a;

  void init_array(int tam) { a.resize(4 * tam); }

  void build(long long array[], int x, int l, int r) {
    if (l == r)
      a[x] = array[l];

    else {
      build(array, 2 * x, l, (l + r) / 2);
      build(array, 2 * x + 1, (l + r) / 2 + 1, r);
      long long s1 = a[2 * x], s2 = a[2 * x + 1];
      a[x] = s1 + s2;
    }
  }

  void update(int i, long long v, int l, int r, int x) {
    if (l == r) {
      a[x] = v;
      return;
    }
    long long m = (l + r) / 2;
    if (i <= m)
      update(i, v, l, m, x * 2);
    else
      update(i, v, m + 1, r, x * 2 + 1);

    a[x] = a[x * 2] + a[x * 2 + 1];
  }

  long long sum(int lx, int rx, int l, int r, int x) {
    if (l > rx || r < lx) return 0;
    if (l >= lx && r <= rx) return a[x];

    long long s1 = sum(lx, rx, l, (l + r) / 2, x * 2),
              s2 = sum(lx, rx, (l + r) / 2 + 1, r, x * 2 + 1);
    return s1 + s2;
  }
};

int main() {
  int n, m;
  seg_tree s;
  scanf("%i %i", &n, &m);
  s.init_array(n);
  long long array[n];
  forr(i, 0, n) scanf("%lli", array + i);

  s.build(array, 1, 0, n - 1);

  forr(i, 0, m) {
    long long q, l, r;
    scanf("%lli %lli %lli", &q, &l, &r);

    if (q == 1)
      s.update(l, r, 0, n - 1, 1);
    else {
      printf("%lli\n", s.sum(l, r - 1, 0, n - 1, 1));
    }
  }

  return 0;
}
