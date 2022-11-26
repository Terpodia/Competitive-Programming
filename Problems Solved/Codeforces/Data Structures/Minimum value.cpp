#include <stdio.h>

#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)

struct seg_tree {
  vector<int> min;

  void size(int tam) { min.resize(tam * 4); }

  void build(int array[], int l, int r, int x) {
    if (l == r)
      min[x] = array[l];
    else {
      int m = (l + r) / 2;
      build(array, l, m, x * 2);
      build(array, m + 1, r, x * 2 + 1);
      min[x] = (min[x * 2] < min[x * 2 + 1]) ? min[x * 2] : min[x * 2 + 1];
    }
  }

  void update(int u, int v, int l, int r, int x) {
    if (l == r) {
      min[x] = v;
      return;
    }
    int m = (l + r) / 2;
    if (u <= m)
      update(u, v, l, m, x * 2);
    else
      update(u, v, m + 1, r, x * 2 + 1);

    min[x] = (min[x * 2] < min[x * 2 + 1]) ? min[x * 2] : min[x * 2 + 1];
  }

  int min_value(int u, int v, int l, int r, int x) {
    if (l > v || r < u)
      return 1e9;
    else if (l >= u && r <= v)
      return min[x];

    int m = (l + r) / 2;
    int i1 = min_value(u, v, l, m, x * 2),
        i2 = min_value(u, v, m + 1, r, x * 2 + 1);

    return (i1 < i2) ? i1 : i2;
  }
};

int main() {
  int n, m, q, u, v;
  seg_tree s;
  scanf("%i %i", &n, &m);
  s.size(n);
  int array[n];

  forr(i, 0, n) scanf("%i", array + i);
  s.build(array, 0, n - 1, 1);

  forr(i, 0, m) {
    scanf("%i %i %i", &q, &u, &v);
    if (q == 1)
      s.update(u, v, 0, n - 1, 1);
    else
      printf("%i\n", s.min_value(u, v - 1, 0, n - 1, 1));
  }

  return 0;
}
