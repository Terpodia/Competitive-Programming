#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct wave {
    ll m, f, w;
    bool operator<(const wave& p) const {
        if(m != p.m) return m < p.m;
        if(f != p.f) return f > p.f;
        return w < p.w;
    }
};

const int MAXN = 3e5+7;

ll dp[MAXN]; int n; wave a[MAXN];

ll bs(ll t, int i) {
    int l = i, r = n, ret = n;

    while(r >= l) {
        int mid = l + (r-l)/2;

        if(a[mid].m >= t) { ret = mid; r = mid-1; }
        else l = mid+1;    
    }
    
    return ret;
}

ll solve(int i) {
    if(i == n) return 0;
    ll& ret = dp[i];
    if(ret != -1) return ret;

    ret = solve(i+1);
    int j=bs(a[i].m + a[i].w, i);

    ret = max(ret, a[i].f + solve(j));

    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lld%lld%lld",&a[i].m, &a[i].f, &a[i].w);

    a[n] = { INF, INF, 0 };

    sort(a, a+n);

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", solve(0));

    return 0;
}
