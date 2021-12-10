/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i,x,n) for(int i=(x); i<(int)n; i++)

const int MAXN = 2e5;

int n, k, h[MAXN];
pair<int,int> a[MAXN];

void solve() {
    bool can = true;

    a[0] = make_pair(h[0], h[0]);
    a[n-1] = make_pair(h[n-1], h[n-1]);

    forn(i,1,n-1) {
        if(h[i] + k <= a[i-1].first) {
            int r = (a[i-1].first - (h[i]+k) + 1);
            
            can &= (r <= k-1);
            a[i].first = h[i] + r;
            a[i].second = a[i].first + (k-1 - r);
        }

        else {
            can &= (a[i-1].second + k > h[i]);
            a[i].first = h[i];
            a[i].second = h[i] + min(k-1, a[i-1].second + k - h[i] - 1);
        }
    }

    can &= (h[n-1] + k > a[n-2].first);
    can &= (a[n-2].second + k > h[n-1]);

    if(can) puts("YES");
    else puts("NO");
}

int main() {
    int t; scanf("%d",&t);

    while(t--) {
        scanf("%d %d",&n,&k);
        forn(i,0,n) scanf("%d",h+i);
        solve();
    }

    return 0;
}

