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

struct DSU{
    vi p, size;
    void init(int n){
        size = vi(n,1); p = vi(n);
        forn(i,0,n) p[i] = i;
    }

    int get(int x){
        if(p[x] != x) return p[x] = get(p[x]); 
        return x;
    }

    void merge(int x, int y){
        int rx = get(x), ry = get(y);
        if(size[rx] < size[ry]){ p[rx] = ry; size[ry] += size[rx]; }
        else { p[ry] = rx; size[rx] += size[ry]; }
    }
};

struct edge{
    int u,v,w;
    bool operator<(const edge& e) const { return w < e.w; }
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

int dist(pi p1, pi p2){
    return (p1.f - p2.f) * (p1.f - p2.f) + (p1.s - p2.s) * (p1.s - p2.s);
}

int main(){
    setIO("moocast");
    int n; cin >> n;
    DSU dsu; dsu.init(n);         

    vector<pi> pos(n);
    vector<edge> edges;

    forn(i, 0, n) cin >> pos[i].f >> pos[i].s;

    forn(i, 0, n) forn(j, 1, n)
        edges.pb({i, j, dist(pos[i], pos[j])});
        
    sort(edges.begin(), edges.end());
    
    int ans = 0;

    forn(i, 0, sz(edges)){
        if(dsu.get(edges[i].u) != dsu.get(edges[i].v)){
            dsu.merge(edges[i].u, edges[i].v);
            ans = max(ans, edges[i].w);
        }
    }

    cout << ans << endl;

	return 0;
}
