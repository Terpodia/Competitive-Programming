#include <cstdio>
#include <cmath>
using ll = long long;
using ld = long double;

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        ld n; scanf("%Lf",&n);
        printf("%lld\n", (ll)(floor( ( -1 + sqrt(1+8*n) ) / 2 )));
    }

    return 0;
}
