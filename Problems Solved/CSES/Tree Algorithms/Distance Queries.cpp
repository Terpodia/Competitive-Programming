#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
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

const int MAXN = 2e5+10;

int n, q, anc[MAXN][23], d[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p=-1){
	if(p != -1) d[u] = d[p]+1;

	anc[u][0] = p;
	fore(i,1,23){
		if(anc[u][i-1] == -1) break;
		anc[u][i] = anc[anc[u][i-1]][i-1];
	}
	for(int v : g[u]) if(v != p){
		dfs(v, u);
	}
}

int dist(int u, int v){	
	int ret = 0;

	if(d[u] < d[v]) swap(u,v);
	dfor(i,23){
		if(anc[u][i] != -1 && d[anc[u][i]] >= d[v])
			u = anc[u][i], ret += (1<<i);
	}
	if(u==v) return ret;
	dfor(i,23){
		if(anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i], ret += (1<<i) * 2;
	}
	return ret+2;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	memset(anc,-1,sizeof(anc));

	cin>>n>>q;
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);

	while(q--){
		int u,v;
		cin>>u>>v;
		u--, v--;
		cout << dist(u,v) << "\n";
	}
	return 0;
}

