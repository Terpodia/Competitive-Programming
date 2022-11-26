#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int N;
  scanf("%d", &N);
  ll A[N], B[N];

  for (int i = 0; i < N; i++) scanf("%lld%lld", A + i, B + i);

  ll C[N], s = 0;

  for (int i = 0; i < N; i++) {
    s += A[i];
    C[i] = 2 * A[i] + B[i];
  }

  sort(C, C + N, greater<ll>());

  int ans = 0;

  for (int i = 0; i < N; i++) {
    s -= C[i], ans++;
    if (s < 0) break;
  }

  printf("%d\n", ans);

  return 0;
}
