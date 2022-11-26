#include <cstdio>

int main() {
  int N;

  while (scanf("%d", &N) != EOF) {
    if (N == 1)
      puts("1");
    else if (N == 0)
      puts("0");
    else
      printf("%d\n", 2 * N - 2);
  }

  return 0;
}
