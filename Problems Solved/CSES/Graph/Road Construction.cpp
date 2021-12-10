/* *************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define deb(x) cout << #x << " " << x << endl;
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define endl "\n"
#define s second
#define f first

const ll INF = 1e18, MOD = 1e9+7;

struct DSU{
    int total;
    vi p, size;

    void init(int n){
        p = vi(n); size = vi(n,1);
        forn(i,0,n) p[i] = i;
        total = n;
    }

    int findSet(int x){
        if(p[x] != x) return p[x] = findSet(p[x]);
        return x;
    }

    void unionSet(int x, int y){
        int rx = findSet(x), ry = findSet(y);
        if(rx != ry){
            total--;
            if(size[rx] < size[ry]) { p[rx] = ry; size[ry] += size[rx]; }
            else { p[ry] = rx; size[rx] += size[ry]; }
        }
    }
};

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void tc(){
	int t, ca = 1; cin >> t;
	while(t--){
		ca++;
	}
}

int main(){
    setIO();
    int n, m; cin >> n >> m;
    DSU dsu; dsu.init(n);
    int size = 1;

    while(m--){
        int u, v; cin >> u >> v; u--; v--;
        dsu.unionSet(u,v);

        size = max(size, dsu.size[dsu.findSet(u)]);
        
        cout << dsu.total << " " << size << endl;
    }

	return 0;
}
