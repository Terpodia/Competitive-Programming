#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, x; scanf("%d%d",&n,&x);
    int h[n], s[n];
    for(int i=0; i<n; i++) scanf("%d",h+i);
    for(int i=0; i<n; i++) scanf("%d",s+i);
    
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int p=0; p<=x; p++){
            int r = p - h[i-1];
            if(r>=0) dp[i][p] = dp[i-1][r] + s[i-1];
            dp[i][p] = max(dp[i][p], dp[i-1][p]);
        }
    }

    printf("%d\n",dp[n][x]);

    return 0;
}
