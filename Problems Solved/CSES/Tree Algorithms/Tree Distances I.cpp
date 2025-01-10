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

const int MAXN = 2e5+10, INF = 1e9;

int n, d[MAXN], ans[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p=-1){
	for(int v : g[u]) if(v != p){
		dfs(v,u);
		d[u] = max(d[u], d[v]+1);
	}
}

void solve(int u, int p=-1){
	for(int v : g[u]) ans[u] = max(ans[u], d[v]+1);

	int pref[len(g[u])+1];
	int suff[len(g[u])+1];

	pref[0]=-INF, suff[len(g[u])]=-INF;
	forn(i,len(g[u])) pref[i+1] = max(pref[i], d[g[u][i]]);
	dfor(i,len(g[u])) suff[i] = max(suff[i+1], d[g[u][i]]);

	forn(i,len(g[u])){
		int v = g[u][i];
		if(v == p) continue;
		int aux = d[u];

		d[u] = 0;
		d[u] = max(d[u], pref[i]+1);
		d[u] = max(d[u], suff[i+1]+1);

		solve(v,u);
		d[u] = aux;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	solve(0);
	forn(i,n) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}

