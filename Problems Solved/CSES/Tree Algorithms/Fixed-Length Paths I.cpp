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

int n, k, m, sz[MAXN];
vector<int> g[MAXN];
bool ok[MAXN];

ll ans;
vector<int> cnt;

void subtree_sz(int u, int p=-1){
	sz[u]=1;
	for(int v : g[u]) if(v != p && !ok[v]){
		subtree_sz(v,u);
		sz[u] += sz[v];
	}
}
int find_centroid(int u, int p=-1){
	for(int v : g[u]) if(v != p && !ok[v]){
		if(sz[v]*2 > m) return find_centroid(v,u);	
	}
	return u;
}
ll add(int u, int cur=1, int p=-1){
	if(cur >= len(cnt)) return 0;
	ll ret = (k-cur >= len(cnt)) ? 0 : cnt[k-cur];
	for(int v : g[u]) if(v != p && !ok[v]){
		ret += add(v, cur+1, u);	
	}
	return ret;
}
void upd(int u, int cur=1, int p=-1){
	if(cur >= len(cnt)) return;	
	cnt[cur]++;	
	for(int v : g[u]) if(v != p && !ok[v]){
		upd(v, cur+1, u);	
	}
}
void solve(int u){
	subtree_sz(u);	
	m = sz[u];
	int c = find_centroid(u);

	ok[c]=true;

	cnt = vector<int>(min(k+1, m/2 + 1), 0);
	cnt[0] = 1;

	for(int v : g[c]) if(!ok[v]){
		ans += add(v);
		upd(v);
	}

	for(int v : g[c]) if(!ok[v]){
		solve(v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}

