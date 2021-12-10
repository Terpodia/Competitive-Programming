#include <iostream>
#include <cstring>

const int MOD = 1e9 + 7;

int main(void)
{
    int n, x; scanf("%d%d",&n,&x);
    int c[n]; for(int i=0; i<n; i++) scanf("%d",c+i);
    
    int dp[x+1]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i=1; i<=x; i++){
        for(int coin : c){
            int r = i - coin;
            if(r < 0) continue;
            dp[i] = (dp[i] + dp[r]) % MOD;
        }
    }

    printf("%d\n", dp[x]);

    return 0;
}
