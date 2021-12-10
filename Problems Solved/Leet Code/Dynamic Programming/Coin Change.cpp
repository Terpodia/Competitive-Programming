#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    const int INF = 1e9;
    vector<int> dp(amount+1, INF);
    dp[0] = 0;

    for(int i=1; i<=amount; i++){
        for(int coin : coins){
            int x = i - coin;
            if(x < 0) continue;
            dp[i] = min(dp[i], dp[x]+1);
        }
    }
    
    return (dp[amount] == INF)? -1 : dp[amount];
}

int main(void)
{
    int n, amount; scanf("%d%d",&n,&amount);
    vector<int> coins(n);
    for(int i=0; i<n; i++) scanf("%d",&coins[i]); 

    printf("%d\n",coinChange(coins, amount));

    return 0;
}
