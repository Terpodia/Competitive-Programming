#include <cstdio>

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n,m; scanf("%d%d",&n,&m);
        printf("%d\n", ((n-2+3-1)/3) * ((m-2+3-1)/3));
    }

    return 0;
}
