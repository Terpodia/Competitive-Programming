#include <cmath>
#include <cstdio>
int aux;

typedef long double ld;

int main() {
  int tc;
  aux = scanf("%d", &tc);
  while (tc--) {
    int N;
    aux = scanf("%d", &N);

    if (N == 1)
      printf("%.3lf\n", 0.0);

    else {
      printf("%.3lf\n",
             N * N - (N - 2) * (N - 2) + sqrt(2) * (N - 2) * (N - 2));
    }
    puts("");
  }

  return 0;
}
