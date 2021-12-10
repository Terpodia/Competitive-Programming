#include <cstdio>
using ll = long long;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        ll n, m, x; scanf("%lld%lld%lld",&n,&m,&x);
        x--;
        ll i = x%n, j = x/n;
        ll ans = (j+(ll)1) + (m*i);
        printf("%lld\n",ans);
    }

    return 0;
}
