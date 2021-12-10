/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define dbg(x) cerr << #x << "=" << x << "\n";
#define line cerr << ".....................................\n"
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define s second
#define f first

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    cout << fixed << setprecision(15); 
}

int n; ll m, a[35];

void calc(vll& p,vll& b,int i,ll acc) {
    if(i==sz(b)) return;
    p.pb(acc%m);
    p.pb((acc+b[i])%m);

    calc(p,b,i+1,acc);
    calc(p,b,i+1,acc+b[i]);
}

int main() {
    setIO();
    cin>>n>>m; 
    forn(i,0,n) cin>>a[i];
    
    if(n==1) { cout << a[0]%m << "\n"; return 0; }

    vll b,c;
    forn(i,0,n/2) b.pb(a[i]);
    forn(i,n/2,n) c.pb(a[i]);

    vll p1, p2;
    calc(p1,b,0,0);calc(p2,c,0,0);
    sort(all(p1)); sort(all(p2));

    ll ans=max(p1[sz(p1)-1], p2[sz(p2)-1]);

    forn(i,0,sz(p1)) {
        auto it = lower_bound(p2.begin(), p2.end(), m-p1[i]); 
        if(it == p2.begin()) continue;
        it--;

        ans=max(ans, *it+p1[i]);
    }

    cout << ans << "\n";

	return 0;
}

