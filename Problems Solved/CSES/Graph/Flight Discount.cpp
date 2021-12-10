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

#define endl "\n"
#define sz(x) (int)x.size()
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define deb(x) cout << #x << " " << x << endl;
#define pb push_back
#define f first
#define s second
#define mp make_pair

const int MAXN = 1e5;
const ll INF = 1e18;

int n, m;
vi G[MAXN]; vl W[MAXN];

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void solve(){
    using T = pair<pair<ll, int>, int>;

    priority_queue<T, vector<T>, greater<T>> pq;   
    vector<vl> dist(n, vl(2, INF));

    pq.push({{0, 0}, 0}); dist[0][0] = dist[0][1] = 0;

    while(!pq.empty()){
        T t = pq.top(); pq.pop();
        int u = t.s; ll d = t.f.f;
        if(d != dist[u][t.f.s]) continue;

        forn(i, 0, sz(G[u])){
            int v = G[u][i]; ll w = W[u][i];
            if(w+d < dist[v][t.f.s]){
                dist[v][t.f.s] = w+d;
                pq.push({{w+d, t.f.s}, v});
            } 

            if(t.f.s == 0 && d+w/2 < dist[v][1]){
                dist[v][1] = d+w/2;
                pq.push({{d+w/2, 1}, v});
            }
        }
    }

    cout << dist[n-1][1] << endl;
}

int main(){
    setIO();
    cin >> n >> m;

    forn(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        G[u-1].pb(v-1); W[u-1].pb(w);
    }

    solve();
    
	return 0;
}
