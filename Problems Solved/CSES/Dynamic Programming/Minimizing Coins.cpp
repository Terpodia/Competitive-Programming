#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1e9;

int main(void)
{
    int n, x; scanf("%d%d",&n,&x); 
    int c[n];
    for(int i=0; i<n; i++) scanf("%d",c+i);

    vector<int> dp(x+1, INF); 
    dp[0] = 0;

    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            int r = i - c[j];
            if(r < 0) continue;
            dp[i] = min(dp[i], dp[r]+1);
        }
    }
    
    printf("%d\n",(dp[x] == INF)? -1 : dp[x]);
    
    return 0;
}
