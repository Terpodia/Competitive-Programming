#include <cstdio>

const int MAXN = 5e4 + 1;

int main() {
  int N, eulerPhi[MAXN];

  for (int i = 0; i < MAXN; i++) eulerPhi[i] = i;
  for (int i = 2; i < MAXN; i++) {
    if (eulerPhi[i] == i) {
      for (int j = i; j < MAXN; j += i)
        eulerPhi[j] = (eulerPhi[j] / i) * (i - 1);
    }
  }

  while (scanf("%d", &N) != EOF && N > 0) {
    int ans = 1;
    for (int i = 2; i <= N; i++) {
      ans += eulerPhi[i] * 2;
    }
    printf("%d\n", ans);
  }

  return 0;
}
