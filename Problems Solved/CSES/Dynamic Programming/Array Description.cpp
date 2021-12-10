#include <cstdio>
#include <cstring>
#include <cmath>
using ll = long long;

const ll MOD = 1e9 + 7;

int main(){
    int n, m; scanf("%d%d",&n,&m);
    int a[n]; for(int i=0; i<n; i++) scanf("%d",a+i);

    ll dp[n][m+1]; memset(dp, 0, sizeof(dp));

    if(a[0] != 0) dp[0][a[0]] = 1;
    else for(int i=1; i<=m; i++) dp[0][i] = 1;

    for(int i=1; i<n; i++){
        if(a[i] != 0){
            ll& c = dp[i][a[i]];
            c += dp[i-1][a[i]]; c %= MOD;
            if(a[i]-1 > 0) { c += dp[i-1][a[i]-1]; c %= MOD; }
            if(a[i]+1 <= m) { c+= dp[i-1][a[i]+1]; c %= MOD; }
        }
        else{
            for(int j=1; j<=m; j++){
                ll& c = dp[i][j];
                c += dp[i-1][j]; c %= MOD;
                if(j-1 > 0) { c += dp[i-1][j-1]; c %= MOD; }
                if(j+1 <= m) { c += dp[i-1][j+1]; c %= MOD; }
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<=m; i++){ ans += dp[n-1][i]; ans %= MOD; }
    
    printf("%lld\n",ans);

    return 0;
}
