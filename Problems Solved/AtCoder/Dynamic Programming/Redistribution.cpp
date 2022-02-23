#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void setIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    setIO();
    ll S; cin >> S;

    ll dp[S+1], sum[S+1];
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[0] = sum[0] = sum[1] = sum[2] = 1;

    for(int i=3; i<=S; i++) {
        dp[i] = sum[i-3];
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }

    cout << dp[S] << "\n";

    return 0;
}
