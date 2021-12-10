#include <cstdio>
using ll = long long;

const int MAXN = 1e5+7;
const ll INF = (ll)1e18 + (ll)1e5 + (ll)7;

int n, q; ll a[MAXN];

ll solve(ll k) {
    ll ans=-1;
    int l=0, r=n;

    while(r >= l) {
        ll mid = l + (r-l)/2;
        if(k+mid > a[mid] && k+mid < a[mid+1]) {
            ans = k+mid;
            r = mid-1;
        }

        else if(k+mid >= a[mid+1]) l = mid+1;

        else r = mid-1;
    }

    return ans;
}

int main() {
    scanf("%d%d",&n, &q);

    a[0] = 0;
    a[n+1] = INF;

    for(int i=1; i<=n; i++) scanf("%lld",a+i);

    while(q--) {
        ll k; scanf("%lld",&k); 
        printf("%lld\n", solve(k));
    }

    return 0;
}
