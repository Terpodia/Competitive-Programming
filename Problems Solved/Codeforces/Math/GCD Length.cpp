#include <cstdio>

typedef long long ll;

int main(){
    int t; scanf("%d",&t);
    ll tenpowers[10];
    ll m=1;

    for(int i=1; i<=9; i++){ tenpowers[i] = m; m *= 10; } 

    while(t--){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        ll _gcd = 1;

        while(_gcd < tenpowers[c]) _gcd*=2;
        ll x = _gcd, y = _gcd;

        while(x < tenpowers[a]) x*=3;
        while(y < tenpowers[b]) y*=5;

        printf("%lld %lld\n", x, y);
    }

    return 0;
}
