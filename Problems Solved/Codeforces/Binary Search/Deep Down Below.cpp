/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define sz(x) (int)x.size()
#define forn(i,x,n) for(int i=(x); i<(int)n; i++)
 
typedef long long ll;
 
const int MAXN = 1e5;
const ll INF = 1e14;
 
int n; vector<ll> a[MAXN];
 
bool ok(vector<pair<ll,ll>>& b, ll p) {
    forn(i,0,n) {
        if(p > 1e9) return true;
        if(p > b[i].first) p += b[i].second;
        else return false;
    }
 
    return true;
}
 
ll solve() {
    vector<pair<ll,ll>> b;
    forn(i,0,n) {
        ll hi=0;
        forn(j,0,sz(a[i])) {
            hi = max(a[i][j]-j, hi);
        }
        b.push_back(make_pair(hi, sz(a[i])));
    }
 
    sort(b.begin(), b.end());

    ll l=0, r = INF;
 
    while(r>l) {
        ll mid = l+(r-l)/2;
        if(ok(b, mid)) r = mid;
        else l = mid+1;
    }
 
    return r;
}
 
int main() {
    int t; scanf("%d",&t);
 
    while(t--) {
        scanf("%d",&n); 
        forn(i,0,n) {
            int k; scanf("%d",&k);
            forn(j,0,k) {
                int v; scanf("%d",&v);
                a[i].push_back(v);
            }
        }
 
        printf("%lld\n", solve());
 
        forn(i,0,n) a[i].clear();
    }
 
    return 0;
}
 
