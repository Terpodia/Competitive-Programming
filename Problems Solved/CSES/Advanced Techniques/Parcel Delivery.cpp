#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i,a,b) for(auto i=a;i<b;i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for(auto i=n;i-->0;)
#define dbg(x) cerr << "LINE" $ __LINE__ <<":" $ #x << "=" << x << endl;
#define raya cerr << "\n-----------------------------------------------------------\n"
#define $ <<" "<<

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T,U> &p){
	os << '(' << p.first $ p.second << ')';
	return os;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
	os << "[";
	forn(i, len(v)){
		if(i) os << ", ";
		os << v[i];
	}
	os << "]";
	return os;
}

typedef long long ll;

const int MAXN = 501;
const int INF = 1e9;

int n,m,k;
vector<int> g[MAXN];
vector<tuple<int,int,int,int>> e;
int d[MAXN];
pair<int,int> par[MAXN];

void bfs(){
    forn(i,n) d[i]=INF, par[i]={-1,-1};
    d[0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [u,p] = q.front();
        q.pop();
        if(p != d[u]) continue;
        for(int i=0; i<len(g[u]); i++){
            auto [v,c,f,r] = e[g[u][i]];
            if(c - f == 0 || d[u]+r >= d[v]) continue;
            
            d[v] = d[u]+r;
            par[v] = {u, i};
            q.push({v,d[v]});
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    forn(i,m){
        int u,v,r,c;
        cin>>u>>v>>r>>c;
        u--,v--;
        e.pb({v,r,0,c});
        e.pb({u,0,0,-c});
        g[u].pb(len(e)-2);
        g[v].pb(len(e)-1);
    }
    int flow=0, cost=0;
    while(flow<k){
        bfs();
        if(d[n-1] == INF) break;
        int lo = INF;
        int cur=n-1;
        while(cur != 0){
            auto [v,c,f,r] = e[g[par[cur].fst][par[cur].snd]];
            lo = min(lo, c-f);
            cur = par[cur].fst;
        }
        lo = min(lo, k-flow);
        cur=n-1;
        flow += lo;
        while(cur != 0){
            int i = g[par[cur].fst][par[cur].snd];
            auto& [v,c,f,r] = e[i];
            f += lo;
            cost += lo * r;
            auto& [v2,c2,f2,r2] = e[i^1]; f2 -= lo;
            cur = par[cur].fst;
        }
    }
    if(flow < k){
        cout<<"-1\n";
        return 0;
    }
    cout<<cost<<"\n";
	return 0;
}
