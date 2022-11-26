#include <cstdio>
#include <cstring>

const int MOD = 1e9 + 7;

int main() {
  int R, G;
  scanf("%d%d", &R, &G);

  int dp[R + 1];
  memset(dp, 0, sizeof(dp));
  int curr[R + 1];

  int h = 1;

  while ((h * (h + 1)) / 2 <= R + G) h++;
  h--;

  for (int r = 0; r <= R; r++) {
    int g = G - ((h * (h + 1)) / 2 - (R - r));
    if (g >= 0) dp[r]++;
  }

  for (int i = h; i >= 1; i--) {
    for (int r = 0; r <= R; r++) {
      int g = G - (((i - 1) * i) / 2 - (R - r));

      if (g < 0) {
        curr[r] = 0;
        continue;
      }

      curr[r] = dp[r];
      if (r - i >= 0) curr[r] += dp[r - i];

      if (curr[r] >= MOD) curr[r] -= MOD;
    }

    for (int r = 0; r <= R; r++) dp[r] = curr[r];
  }

  printf("%d\n", dp[R]);

  return 0;
}
