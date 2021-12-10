#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

#define f first
#define s second

const int MAXN = 1e5; 

int n;
ll c[MAXN];

ll solve(){
    ll ans = c[0]*n + c[1]*n; 
    ii sx = {0, c[0]}, sy = {0, c[1]};
    
    ll minX = c[0], minY = c[1];

    for(int i=2; i<n; i++){
        if(i%2==0){
            sx.f++; sx.s += c[i]; 
            minX = min(minX, c[i]);
        }
        else{
            sy.f++; sy.s += c[i];
            minY = min(minY, c[i]);
        }
        ll sum = (sx.s - minX + minX*(n-sx.f)) + (sy.s - minY + minY*(n-sy.f));
        ans = min(ans, sum);
    }

    return ans;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%lld",c+i);
        printf("%lld\n", solve());
    }

    return 0;
}
