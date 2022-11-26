#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX (int)1e6

int main() {
  int A, B, W;
  scanf("%d%d%d", &A, &B, &W);

  int lo = MAX, hi = -MAX;

  for (int i = 1; i <= MAX; i++) {
    if (W * 1000 >= A * i && W * 1000 <= B * i) {
      lo = min(i, lo);
      hi = max(i, hi);
    }
  }

  (hi == -MAX) ? puts("UNSATISFIABLE") : printf("%d %d\n", lo, hi);

  return 0;
}
