#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, C;

void solve() {
  if (C < N - 1 || C > N * (N + 1) / 2 - 1) {
    puts("IMPOSSIBLE");
    return;
  }

  C -= N - 1;
  int ans[N], swaps[N];
  for (int i = 0; i < N; i++) {
    int p = min(C + i, N - 1);
    swaps[i] = p;
    C -= p - i;

    int aux[N];
    memset(aux, -1, sizeof(aux));
    aux[p] = 0;

    for (int j = i - 1; j >= 0; j--) reverse(aux + j, aux + swaps[j] + 1);

    int pos;
    for (int j = 0; j < N; j++) {
      if (aux[j] == 0) {
        pos = j;
        break;
      }
    }
    ans[pos] = i + 1;
  }

  for (int i = 0; i < N; i++) printf("%d ", ans[i]);
  puts("");
}

int main() {
  int t, x = 1;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &N, &C);
    printf("Case #%d: ", x);
    solve();
    x++;
  }

  return 0;
}
