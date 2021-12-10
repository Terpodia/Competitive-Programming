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
using ld = long double;

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
#define mp make_pair

const int MAXN = 1000;
int N, M; vi G[MAXN]; vector<pair<ld, ld>> W[MAXN];

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void solve(){
    vector<ld> dist(N, -1);
    using T = pair<ld, pair<int, pair<ld, ld>>>;

    priority_queue<T> pq;
    pq.push({0, {0, {0, 1e9}}}); dist[0] = 0;

    while(!pq.empty()){
        T p = pq.top(); pq.pop();
        int u = p.second.first; ld d = p.first;
        if(d != dist[u]) continue; 

        forn(i, 0, sz(G[u])){
            int v = G[u][i]; ld c = W[u][i].first, f = W[u][i].second;
            ld lo = min(f, p.second.second.second); 
            ld w = c + p.second.second.first; 
            if(lo/w > dist[v]){
                dist[v] = lo/w;
                pq.push({dist[v], {v, {w, lo}}});
            }
        }
    }

    cout << (ll)(dist[N-1] * 1e6) << endl;
}

int main(){
    setIO("pump");
    cin >> N >> M;
    forn(i, 0, M){
        int a, b, c, f; cin >> a >> b >> c >> f;
        G[a-1].pb(b-1); G[b-1].pb(a-1);
        W[a-1].pb({c, f}); W[b-1].pb({c, f});
    }

    solve();
    
	return 0;
}
