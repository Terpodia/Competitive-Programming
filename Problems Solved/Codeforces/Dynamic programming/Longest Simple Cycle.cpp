#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;

int n; ll c[MAXN], a[MAXN], b[MAXN], dp[MAXN][2];

ll solve(int i, int flag) {
    if(i==0) 
        return (flag==0)? 0 : abs(a[i+1]-b[i+1]);
    
    ll& ret = dp[i][flag];
    if(ret != -1) return ret; 

    if(flag==0) {
        return ret = max(solve(i-1, 0), c[i]+1 + solve(i-1, 1));
    }

    ll u=a[i+1], v=b[i+1];
    if(u>v) swap(u,v);

    if(u == v) return ret = 0;

    return ret = max(v - u, u + c[i] - v + 1 + solve(i-1, 1));
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%lld",c+i);
        for(int i=0; i<n; i++) scanf("%lld",a+i);
        for(int i=0; i<n; i++) scanf("%lld",b+i);

        memset(dp, -1, sizeof(dp));

        printf("%lld\n", solve(n-1, 0));
    }

    return 0;
}

