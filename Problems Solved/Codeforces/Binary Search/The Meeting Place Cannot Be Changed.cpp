#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

const int MAXN = 6e4;
const ld INF = 1e9;
const ld EPS = 1e-7;

int n;
ld x[MAXN], v[MAXN];

bool can(ld t) {
    pair<ld, ld> s[n];
    for(int i=0; i<n; i++) { 
        s[i] = make_pair(x[i] - v[i]*t, x[i] + v[i]*t); 
    }

    sort(s, s+n);

    ld r = s[0].second;
    for(int i=1; i<n; i++) {
        if(s[i].first > r) return false;
        r = min(s[i].second, r);
    }

    return true;
}

ld solve() {
    int cnt=0;
    ld l=0, r=INF, ans=INF;

    while(cnt < 70) {
        ld mid = l + (r-l)/2;
        if(can(mid)) { ans = mid; r = mid - EPS; } 
        else l = mid + EPS;

        cnt++;
    }

    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%Lf", x+i);
    for(int i=0; i<n; i++) scanf("%Lf", v+i);

    printf("%.12Lf\n", solve());

    return 0;
}
