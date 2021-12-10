#include <cstdio>

typedef long long ll;

int main() {
    int t; scanf("%d",&t);
    
    while(t--) {
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if(a <= b) printf("%lld\n", b);
        else {
            if(d >= c) puts("-1");
            else {
                a -= b; 
                printf("%lld\n", b + c * ((a+(c-d)-1) / (c-d)));
            }
        }
    }

    return 0;
}

