#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, m, k;

bool ok(ll c) {
    ll l=-1, r=0;

    for(ll i=1; i<=n; i++) {
        ll j = (c+i-1)/i;
        if(j > m || j < 1) continue; 

        if(i*j == c) l++, j++;
        if(j <= m) r += m-j+1;
    }

    if(l != -1) r += l;
    return (n*m - r <= k);
}

ll bs(ll i, ll x) {
    ll l=0, r=m;

    while(r > l) {
        ll mid = l + (r-l+1)/2;
        if(i * mid <= x) l = mid; 
        else r = mid-1;
    }

    return (l == 0)? -1 : r;
}

ll solve() {
    ll l = 1, r = n * m;

    while(r > l) {
        ll mid = l + (r-l+1)/2;
        if(ok(mid)) l = mid;
        else r = mid-1;
    }

    ll ret=-1;

    for(int i=1; i<=n; i++) {
        ll j = bs(i, l);
        if(j != -1) ret = (l - ret <= l - i*j)? ret : i*j;
    }
    
    return ret;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    
    printf("%lld\n", solve());

    return 0;
}

