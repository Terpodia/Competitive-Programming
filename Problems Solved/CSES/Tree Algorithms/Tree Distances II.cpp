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
 
int n;
ll ans[MAXN], sum[MAXN], cnt[MAXN];
 
vector<int> g[MAXN];
 
void dfs(int u, int p=-1){
	cnt[u]=1, sum[u]=0;
	for(int v : g[u]) if(v != p){
		dfs(v,u);
		cnt[u] += cnt[v];
		sum[u] += sum[v];
	}
	sum[u] += cnt[u]-1LL;
}
 
void solve(int u, int p=-1){
	ll cur_cnt=0;
	ans[u]=0;
	for(int v : g[u]) cur_cnt += cnt[v], ans[u] += sum[v];
	ans[u] += cur_cnt;
	ll pref_cnt[len(g[u])+1];
	ll pref_sum[len(g[u])+1];
	pref_cnt[0] = pref_sum[0] = 0;
	forn(i,len(g[u])) pref_cnt[i+1] = pref_cnt[i] + cnt[g[u][i]];
	forn(i,len(g[u])) pref_sum[i+1] = pref_sum[i] + sum[g[u][i]];
 
	forn(i,len(g[u])){
		int v = g[u][i];
		if(v == p) continue;
 
		ll aux1 = sum[u], aux2 = cnt[u];
 
		cnt[u] = 1LL + pref_cnt[i] + pref_cnt[len(g[u])] - pref_cnt[i+1];
		sum[u] = pref_sum[i] + pref_sum[len(g[u])] - pref_sum[i+1] + cnt[u] - 1LL;
 
		solve(v,u);
		sum[u] = aux1, cnt[u] = aux2;
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

