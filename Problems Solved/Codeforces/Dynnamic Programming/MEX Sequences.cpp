#include <cstdio>
#include <cstring>
 
typedef long long ll;
 
const ll MOD = 998244353; 
 
int main() {
  int t; scanf("%d",&t);
  while (t--) {
    int n; scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++)
      scanf("%d",a+i);
 
    ll dp[n+2][2];
    for (int i=0; i<n+2; i++) dp[i][0] = dp[i][1] = 1;
 
    for (int i=n-1; i>-1; i--) {
      dp[a[i]][0] = (dp[a[i]][0] + dp[a[i]+1][0]) % MOD;
      dp[a[i]+1][0] = (dp[a[i]+1][0] + dp[a[i]+1][0]) % MOD;
 
      if (a[i] > 0) 
        dp[a[i]-1][0] = (dp[a[i]-1][0] + dp[a[i]-1][1]) % MOD;
 
      if (a[i] > 0)
        dp[a[i]-1][1] = (dp[a[i]-1][1] + dp[a[i]-1][1]) % MOD;
 
      dp[a[i]+1][1] = (dp[a[i]+1][1] + dp[a[i]+1][1]) % MOD;
    }    
 
    printf("%lld\n", ((dp[0][0] - 1) + MOD) % MOD);
  }
 
  return 0;
}

