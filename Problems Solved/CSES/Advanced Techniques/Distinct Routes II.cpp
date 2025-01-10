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

void add_edge(int u, int v, int cap, int cost){
	e.pb({v,cap,0,cost});
	e.pb({u,0,0,-cost});
	g[u].pb(len(e)-2);
	g[v].pb(len(e)-1);
}
void bfs(int s){
    forn(i,n) d[i]=INF, par[i]={-1,-1};
    d[s]=0;
    queue<pair<int,int>> q;
    q.push({s,0});
    while(!q.empty()){
        auto [u,cur] = q.front();
        q.pop();
        if(cur != d[u]) continue;
        for(int i=0; i<len(g[u]); i++){
            auto [v,cap,flow,cost] = e[g[u][i]];
            if(cap - flow == 0 || d[u]+cost >= d[v]) continue;
            
            d[v] = d[u]+cost;
            par[v] = {u, i};
            q.push({v,d[v]});
        }
    }
}
int max_flow_min_cost(int s, int t){
	int cur_flow=0, cur_cost=0;
	while(cur_flow<k){
		bfs(s);
		if(d[t] == INF) break;
        int lo = INF;
        int cur=t;
        while(cur != s){
            auto [v,cap,flow,cost] = e[g[par[cur].fst][par[cur].snd]];
            lo = min(lo, cap-flow);
            cur = par[cur].fst;
        }
        lo = min(lo, k-cur_flow);
        cur_flow += lo;
        cur=t;
        while(cur != s){
            int i = g[par[cur].fst][par[cur].snd];
            auto& [v,cap,flow,cost] = e[i];
            flow += lo;
            cur_cost += lo * cost;
			auto& rflow = get<2>(e[i^1]);
			rflow -= lo;
            cur = par[cur].fst;
        }
	}
	return (cur_flow == k) ? cur_cost : -1;
}

vector<vector<int>> ans;
vector<int> vert;
bool vis[MAXN][MAXN];
void dfs(int u){
	vert.pb(u+1);
	if(u==n-1){
		ans.pb(vert);
		vert.pop_back();
		return;
	}
	for(int i : g[u]) if(i%2==0){
		auto& [v,cap,flow,cost] = e[i];	
		if(vis[u][v] || flow==0) continue;
		vis[u][v]=true;
		dfs(v);
		if(u != 0){
			vert.pop_back();
			return;
		}
	}
	vert.pop_back();
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    forn(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
		add_edge(u,v,1,1);
    }
	int res = max_flow_min_cost(0,n-1);
	cout << res << "\n";
	if(res == -1) return 0;
	dfs(0);

	forn(i,len(ans)){
		cout << len(ans[i]) << "\n";
		for(int j : ans[i]) cout << j << " ";
		cout<<"\n";
	}
	return 0;
}

