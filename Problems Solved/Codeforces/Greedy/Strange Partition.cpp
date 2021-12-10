#include <stdio.h>

typedef long long ll;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        ll n, x; scanf("%lld%lld",&n,&x);
        ll a[n];
        for(int i = 0; i < n; i++) scanf("%lld",a+i);

        ll lo = 0, hi = 0;
        
        for(int i = 0; i < n; i++){
            ll d = 1 + (a[i] - 1) / x;
            hi += d;
            lo += a[i];
        }
        
        lo = 1 + (lo - 1)/x;
        printf("%lld %lld\n",lo,hi);
    }

    return 0;
}
