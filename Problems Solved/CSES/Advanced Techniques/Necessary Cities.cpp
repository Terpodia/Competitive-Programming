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

const int MAXN = 1e5+10;

vector<int> g[MAXN], ans;
int cnt[MAXN], low[MAXN];

void dfs(int u, int p=-1){
	cnt[u] = (p != -1) ? cnt[p] : 0;
	cnt[u]++;
	low[u] = cnt[u];

	int sz=0;

	bool art=false;
	for(int v : g[u]) if(v != p){
		if(cnt[v] != 0) low[u]=min(low[u], cnt[v]);
		else{
			sz++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v] >= cnt[u]) art=true;
		}
	}
	if(art && p != -1) ans.pb(u+1);
	else if(p == -1 && sz>1) ans.pb(u+1);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	forn(i,m){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	cout << len(ans) << "\n";
	for(int i : ans) cout<<i<<" ";
	cout<<"\n";
	return 0;
}

