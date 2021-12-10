#include <cstdio>
#include <cmath>
using ll = long long;

int main() {
    int n; scanf("%d",&n);
    ll a[n];
    for(int i=0; i<n; i++) scanf("%lld",a+i);

    ll curr=a[0], ans=a[0]+1;

    for(int i=1; i<n; i++) {
        ans += abs(a[i] - curr) + 2; 
        curr = a[i];
    }

    printf("%lld\n", ans);

    return 0;
}
