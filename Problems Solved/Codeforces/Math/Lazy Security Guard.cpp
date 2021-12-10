#include <cstdio>

typedef long long ll;

int main() {
    ll n; scanf("%lld",&n);
    ll m=1;

    while(m*m < n && (m+1)*(m+1) <= n) m++;

    if(n == (m*m)) printf("%lld\n", m*4);
    else if(n <= m*m + m) printf("%lld\n", m*4+2);
    else printf("%lld\n", m*4+4);

    return 0;
}
