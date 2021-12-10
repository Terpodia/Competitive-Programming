#include <cstdio>

int main(){
    int t; scanf("%d", &t);

    while(t--){
        long long A, B; scanf("%lld%lld",&A,&B);
        if(B == 1) puts("NO");
        else printf("YES\n%lld %lld %lld\n", A, A*B, A*(B+1));
    }

    return 0;
}
