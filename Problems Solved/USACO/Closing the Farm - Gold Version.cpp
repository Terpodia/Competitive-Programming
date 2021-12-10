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
    int total; vi p, size; 
    
    void init(int n){
        total = n;
        size = vi(n,1); p = vi(n);
        forn(i,0,n) p[i] = i;
    }

    int get(int x){
        if(p[x] != x) return p[x] = get(p[x]);
        return x;
    }

    void merge(int x, int y){
        int rx = get(x), ry = get(y);

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
    setIO("closing");
    int N, M; cin >> N >> M;
    DSU dsu; dsu.init(N);

    vector<vi> G(N);
    vector<bool> flags(N, false);

    forn(i, 0, M){
        int u,v; cin >> u >> v;
        G[u-1].pb(v-1); G[v-1].pb(u-1);
    }

    vector<bool> ans(N);
    vector<int> queries(N); forn(i, 0, N) cin >> queries[i];

    int cnt = N;

    rforn(i, N-1, 0){
        flags[queries[i]-1] = true; 
        cnt--;

        for(int v : G[queries[i]-1])
            if(flags[v]) dsu.merge(queries[i]-1, v);

        ans[i] = (dsu.total - cnt < 2);
    }

    forn(i,0,N){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

	return 0;
}
