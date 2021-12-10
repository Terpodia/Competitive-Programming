#include <iostream>
#include <cstring>
 
const int MOD = 1e9 + 7;
 
int main(void)
{
    int n, x; scanf("%d%d",&n,&x);
    int c[n]; for(int i=0; i<n; i++) scanf("%d",c+i);
 
    int dp[n+1][x+1]; memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            int r = j - c[i-1];
            if(r>=0) dp[i][j] = dp[i][r];
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
        }
    }
 
    printf("%d\n", dp[n][x]);
 
    return 0;
}
