#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n; scanf("%d",&n);
        ll a[n];
        for(int i=0; i<n; i++) scanf("%lld",a+i);

        ll s=0;
        for(int i=0; i<n; i++) s += a[i];

        ll d = s/n, r = s%n;

        for(int i=n-1; i>=0; i--) {
            a[i] = d;
            if(r > 0) a[i]++, r--;
        }

        ll suff[n]; suff[n-1] = a[n-1];

        for(int i=n-2; i>=0; i--) suff[i] = suff[i+1] + a[i];

        ll ans=0;
        for(int i=0; i<n-1; i++) ans += suff[i+1] - (a[i] * (n-1-i));

        printf("%lld\n", ans);
    }


    return 0;
}
