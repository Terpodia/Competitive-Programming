#include <cstdio>

typedef long long ll;

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        ll k; scanf("%lld",&k);
        ll r=1, c=1, val=1;
        
        for(ll i=1; true; i++) {
            if(k <= i*i) { val=i*i, r=i; break; }
        }

        ll ans_r = r, ans_c = c;

        for(ll i=0; i<r; i++) {
            ans_c = c+i;
            if(val == k) break;
            if(i<r-1) val--;
        }

        for(ll i=0; i<r; i++) {
            ans_r = r-i;
            if(val == k) break;
            val--;
        }

        printf("%lld %lld\n", ans_r, ans_c);
    }

    return 0;
}

