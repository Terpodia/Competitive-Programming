#include <iostream>
#include <map>
using namespace std;
using ii = pair<int, int>;

map<pair<ii, ii>, long long> dp;

int N, M;

long long solve(int i, int j, int A, int B, int msk) {
  if (i == N) return 1;
  if (j == M) return solve(i + 1, 0, A, B, msk);

  int id = i * M + j;

  if (msk & (1 << id)) return solve(i, j + 1, A, B, msk);

  if (dp.find({{id, msk}, {A, B}}) != dp.end()) return dp[{{id, msk}, {A, B}}];

  long long ret = 0;

  if (A > 0) {
    if (j + 2 <= M) {
      int nmsk = msk | (1 << id);
      nmsk |= 1 << (id + 1);
      ret += solve(i, j + 2, A - 1, B, nmsk);
    }

    if (i + 2 <= N) {
      int nmsk = msk | (1 << id);
      nmsk |= 1 << ((i + 1) * M + j);
      ret += solve(i, j + 1, A - 1, B, nmsk);
    }
  }

  if (B > 0) {
    int nmsk = msk | (1 << id);
    ret += solve(i, j + 1, A, B - 1, nmsk);
  }

  return dp[{{id, msk}, {A, B}}] = ret;
}

int main() {
  int A, B;
  scanf("%d%d%d%d", &N, &M, &A, &B);

  printf("%lld\n", solve(0, 0, A, B, 0));

  return 0;
}
