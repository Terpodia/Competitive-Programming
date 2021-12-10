#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();
    int n, k; cin >> n >> k;
    pair<int,int> p[k];

    for(int i=0; i<k; i++) cin >> p[i].first >> p[i].second;

    ll dp[n+1], pref[n+1]; 
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    dp[1] = pref[1] = 1;

    for(int i=2; i<=n; i++) {
        for(int j=0; j<k; j++) {
            if(p[j].first >= i) continue;
            int r = i - p[j].first; 
            int l = max(1, i - p[j].second);
            
            ll s = (((pref[r] - pref[l-1]) % MOD) + MOD) % MOD;

            dp[i] = (dp[i] + s) % MOD;
        }

        pref[i] = (pref[i-1] + dp[i]) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}
