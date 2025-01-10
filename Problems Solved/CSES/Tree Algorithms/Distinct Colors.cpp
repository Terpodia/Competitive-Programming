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
 
int n, c[MAXN], ans[MAXN];
vector<int> g[MAXN];
 
set<int> dfs(int u, int p=-1){
	set<int> ret;
	ret.insert(c[u]);
	for(int v : g[u]) if(v != p){
		set<int> aux = dfs(v, u);
		if(len(aux) > len(ret)) swap(aux, ret);
		for(int i : aux) ret.insert(i);
	}
	ans[u] = len(ret);
	return ret;
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	forn(i,n) cin>>c[i];
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	forn(i,n) cout << ans[i] << " ";
	cout<<"\n";
	return 0;
}

