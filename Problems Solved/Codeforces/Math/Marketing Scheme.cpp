#include <cstdio>
using ld = long double;

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        ld l, r; scanf("%Lf%Lf",&l,&r); 
        ((r+1)/2 <= l)? puts("YES") : puts("NO");
    }

    return 0;
}
