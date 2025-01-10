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

int n, m, p[MAXN], anc[MAXN][23], d[MAXN], cnt[MAXN];
vector<int> g[MAXN];
pair<int,int> acc[MAXN];

void dfs(int u){
	if(p[u] != -1) d[u] = d[p[u]]+1;

	anc[u][0] = p[u];
	fore(i,1,23){
		if(anc[u][i-1] == -1) break;
		anc[u][i] = anc[anc[u][i-1]][i-1];
	}
	for(int v : g[u]) if(v != p[u]){
		cnt[u]++;
		p[v] = u;
		dfs(v);
	}
}

int lca(int u, int v){	
	if(d[u] < d[v]) swap(u,v);
	dfor(i,23){
		if(anc[u][i] != -1 && d[anc[u][i]] >= d[v])
			u = anc[u][i];
	}
	if(u==v) return u;
	dfor(i,23){
		if(anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	}
	return anc[u][0];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(p,-1,sizeof(p));
	memset(anc,-1,sizeof(anc));
	dfs(0);

	forn(i,n) acc[i]={0,0};
	forn(i,m){
		int u,v;
		cin>>u>>v;
		u--, v--;
		acc[u].fst++, acc[v].fst++;
		int l = lca(u, v);
		acc[l].snd++;
	}
	queue<int> q;
	forn(i,n){
		if(cnt[i] == 0) q.push(i);
	}

	vector<int> ans(n,0), cur(n,0);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		//dbg(u);

		cur[u] += acc[u].fst - acc[u].snd;
		ans[u] = cur[u];
		cur[u] -= acc[u].snd;

		if(p[u] != -1){
			cnt[p[u]]--;
			cur[p[u]] += cur[u];

			if(cnt[p[u]] == 0) q.push(p[u]);
		}
	}

	forn(i,n) cout << ans[i] << " ";
	cout<<"\n";
	return 0;
}

