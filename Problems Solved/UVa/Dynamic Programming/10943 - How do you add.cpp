#include <cstdio>
#include <cstring>

const int MOD = 1e6;

int n, k, dp[101][101];

int solve(int i, int cnt) {
  if (i == k) return (cnt == n) ? 1 : 0;
  if (cnt > n) return 0;
  int& ret = dp[i][cnt];
  if (ret != -1) return ret;
  ret=0;
  for (int j=0; j<n+1; j++) {
    ret+=solve(i+1, cnt+j);
    ret%=MOD;
  }
  return ret;
}

int main() {
  while (scanf("%d%d",&n,&k) != EOF && !(n == 0 && k == 0)) {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0)); 
  } 
  return 0;
}

