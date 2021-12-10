#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, l, r;
vector<int> a;

int bs1(int x, int y) {
    int ret=-1, lo = x+1, hi = n-1;

    while(hi >= lo) {
        int mid = lo + (hi-lo)/2;
        if(a[mid] + y >= l && a[mid] + y <= r) {
            ret = mid;
            hi = mid-1;
        }

        else if(a[mid] + y >= r) hi = mid-1;

        else lo = mid+1; 
    }

    return ret;
}

int bs2(int x, int y) {
    int ret=-1, lo = x+1, hi = n-1;

    while(hi >= lo) {
        int mid = lo + (hi-lo)/2;
        if(a[mid] + y >= l && a[mid] + y <= r) {
            ret = mid;
            lo = mid+1;
        }

        else if(a[mid] + y >= r) hi = mid-1;
        
        else lo = mid+1; 
    }

    return ret;
}

ll solve() {
    ll ret=0;

    for(int i=0; i<n; i++) {
        int p = bs1(i, a[i]);
        if(p == -1) continue;
        ret += (ll)bs2(i, a[i]) - (ll)p + (ll)1;
    }

    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&n,&l,&r); 
        a = vector<int>(n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);

        sort(a.begin(), a.end());

        printf("%lld\n", solve());
    }


    return 0;
}
