#include <cstdio>

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n, a[50];
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i);

        int s=0;
        for(int i=0; i<n; i++) s+=a[i];

        if(s == n) puts("0");
        else if(s < n) puts("1");
        else printf("%d\n", s - n);
    }

    return 0;
}
