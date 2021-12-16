#include <cstdio>
int aux;

int main() {
    int t; aux=scanf("%d",&t);
    while (t--) {
        int n; aux=scanf("%d",&n);
        if (n % 2 == 0) printf("%d %d %d\n", n-3, 2, 1);
        else {
            if ((n / 2) % 2 == 0) printf("%d %d %d\n", n/2 - 1, n/2 + 1, 1);
            else printf("%d %d %d\n", n/2 - 2, n/2 + 2, 1);
        }
    }

    return 0;
}
