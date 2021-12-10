#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;

int n; ll k;
ll a[MAXN], pref[MAXN+7];

ll bs(ll mx) {
    ll l=1, r=mx-1, ret=mx;

    while(r >= l) {
        ll mid = l + (r-l)/2;

        if(a[mx-1]*(mx-mid) - (pref[mx-1] - pref[mid-1]) <= k) {
            r = mid-1;
            ret = mid;
        }

        else l = mid+1;
    }

    return ret;
}

void solve() {
    pair<ll,ll> ans = make_pair(1, a[0]);

    for(int i=2; i<=n; i++) {
        ll pos = bs(i);  
        if(i-pos+1 > ans.first) ans = make_pair(i-pos+1, a[i-1]);
    }

    printf("%lld %lld\n", ans.first, ans.second);
}

int main() {
    scanf("%d%lld",&n,&k);
    for(int i=0; i<n; i++) scanf("%lld",a+i); 
    sort(a, a+n);
    pref[0] = a[0];
    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];

    solve();

    return 0;
}
