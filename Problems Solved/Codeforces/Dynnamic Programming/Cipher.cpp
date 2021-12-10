#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define sz(x) (int)x.size()

const int MOD = 1e9 + 7;
const int MAXSM = 26 * 100 + 7;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();
    int t; cin >> t;

    int dp[101][MAXSM+1]; memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;

    for(int i=1; i<101; i++) {
        int pref[MAXSM+1];
        pref[0] = dp[i-1][0];

        for(int j=1; j<=MAXSM; j++) 
            pref[j] = (dp[i-1][j] + pref[j-1]) % MOD;

        for(int j=1; j<=MAXSM; j++) {
            int r = min(j,26);
            if(j-r-1 < 0) 
                dp[i][j] = pref[j-1] % MOD;

            else
                dp[i][j] = (pref[j-1] - pref[j-r-1] + MOD) % MOD;
        }
    }

    while(t--) {
        string a; cin >> a; 
        int s=0;
        for(char c : a) s += c-'a'+1;

        printf("%d\n", dp[sz(a)][s] - 1);
    }

    return 0;
}

