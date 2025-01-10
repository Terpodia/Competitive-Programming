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

const ll MOD=1e9+7;
const int MAXN=1e5+10;

ll res=1;
vector<int> g[MAXN];
int cnt[MAXN];

void dfs(int u, int p=-1){
	cnt[u] = 1 + ((p != -1) ? cnt[p] : 0);	
	for(int v : g[u]) if(v != p){
		if(cnt[v]==0) dfs(v,u);
		else if(cnt[v] < cnt[u]) res = (res * 2LL) % MOD;
	}
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
	forn(i,n){
		if(cnt[i]==0) dfs(i);
	}
	cout << res << "\n";
	return 0;
}

