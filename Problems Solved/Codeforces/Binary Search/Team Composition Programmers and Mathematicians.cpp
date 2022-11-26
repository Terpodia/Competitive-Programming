#include <cstdio>
int aux;

const int INF = 1e9;

bool can(int k, int a, int b) {
  if (a < k || b < k) return false;
  a -= k;
  b -= k;

  return a + b >= 2 * k;
}

int bs(int a, int b) {
  int l = 0, r = INF;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (can(mid, a, b))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int a, b;
    aux = scanf("%d%d", &a, &b);
    printf("%d\n", bs(a, b));
  }

  return 0;
}
