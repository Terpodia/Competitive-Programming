#include <algorithm>
#include <cstdio>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  int N;
  scanf("%d", &N);
  ll C[N];
  for (int i = 0; i < N; i++) scanf("%lld", C + i);

  sort(C, C + N);

  ll cnt = 0, ans = 1;

  for (int i = 0; i < N; i++) {
    ans = (ans * (C[i] - cnt)) % MOD;
    cnt++;
  }

  printf("%lld\n", ans);

  return 0;
}
