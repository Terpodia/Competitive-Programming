#include <cstdio>

int aux;

int main() {
    int t; aux=scanf("%d",&t);
    while(t--) {
        int n; aux=scanf("%d",&n);
        int ans = n/10;
        if(n%10==9)ans++;
        printf("%d\n", ans);
    }

    return 0;
}

