#include <cstdio>

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int l, r; scanf("%d%d",&l,&r);
        if(l*2 > r) puts("-1 -1");
        else printf("%d %d\n", l, l*2);
    }

    return 0;
}

