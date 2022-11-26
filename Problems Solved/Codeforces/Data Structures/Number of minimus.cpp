#include <stdio.h>

#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef pair<int, int> ii;

struct seg_tree {
  vector<ii> min;

  void size(int tam) { min.resize(tam * 4); }

  ii minimo(ii a, ii b) {
    if (a.first < b.first)
      return a;
    else if (a.first > b.first)
      return b;
    return {a.first, a.second + b.second};
  }

  void build(int array[], int l, int r, int x) {
    if (l == r)
      min[x] = {array[l], 1};
    else {
      int m = (l + r) / 2;
      build(array, l, m, x * 2);
      build(array, m + 1, r, x * 2 + 1);

      min[x] = minimo(min[x * 2], min[x * 2 + 1]);
    }
  }

  void update(int u, int v, int l, int r, int x) {
    if (l == r) {
      min[x] = {v, 1};
      return;
    }

    int m = (l + r) / 2;
    if (u <= m)
      update(u, v, l, m, x * 2);
    else
      update(u, v, m + 1, r, x * 2 + 1);

    min[x] = minimo(min[x * 2], min[x * 2 + 1]);
  }

  ii solve(int u, int v, int l, int r, int x) {
    if (l > v || r < u) return {1e9, 0};
    if (l >= u && r <= v) return min[x];

    int m = (l + r) / 2;
    ii i1 = solve(u, v, l, m, x * 2), i2 = solve(u, v, m + 1, r, x * 2 + 1);
    return minimo(i1, i2);
  }
};

int main() {
  int n, m, q, u, v;
  ii answer;
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
    else {
      answer = s.solve(u, v - 1, 0, n - 1, 1);
      printf("%i %i\n", answer.first, answer.second);
    }
  }

  return 0;
}
