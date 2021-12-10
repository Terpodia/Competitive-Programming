#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int n; scanf("%d",&n);
    ll a[n];
    for(int i=0; i<n; i++) scanf("%lld",a+i);

    ll pos=0, hi=-INF, s=0, ans=0;

    for(int i=0; i<n; i++) {
         s += a[i];
         hi = max(s, hi);
         ans = max(ans, pos+hi);

         pos += s;
    }

    printf("%lld\n", ans);

    return 0;
}
