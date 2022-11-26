#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 20, INF = (1 << 30) + 7;

int N, a[MAXN];

int solve(int i, int XOR) {
  if (i == N) return XOR;

  int OR = 0, ret = INF;

  for (int j = i; j < N; j++) {
    OR |= a[j];
    ret = min(ret, solve(j + 1, XOR ^ OR));
  }

  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", a + i);

  printf("%d\n", solve(0, 0));

  return 0;
}
