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

const int MAXN = 50;

int n, m;
vi G[MAXN]; bool vis[MAXN];

ll DFS(int u) {
    vis[u] = true;
    ll ret=1;
    for(int v : G[u]) {
        if(vis[v]) continue; 
        ret += DFS(v);
    }
    return ret;
}

int main() {
    setIO();
    cin >> n >> m;
    forn(i,0,m) {
        int u,v; cin>>u>>v;
        G[u-1].pb(v-1); G[v-1].pb(u-1);
    }

    ll ans=1;

    forn(i,0,n) {
        if(!vis[i]) {
            ll cnt = DFS(i);
            cnt--;
            ans *= (1LL<<cnt);
        }
    }

    cout << ans << "\n";

	return 0;
}

