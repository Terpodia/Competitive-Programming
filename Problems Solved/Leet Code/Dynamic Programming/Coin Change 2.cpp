#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

unsigned long long change(int amount, vector<int>& coins)
{
    int N = (int)coins.size();

    unsigned long long dp[amount+1][N+1];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=N; i++) dp[0][i] = 1;
    
    for(int s=1; s<=amount; s++){
        for(int k=1; k<=N; k++){
            int r = s-coins[k-1];
            if(r >= 0) dp[s][k] += dp[r][k];
            dp[s][k] += dp[s][k-1];
        }
    }

    return dp[amount][N];
}

int main(void)
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    cout << change(amount, coins) << "\n";

    return 0;
}
