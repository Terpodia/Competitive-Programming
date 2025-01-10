//#pragma GCC optimize("O3,unroll-loops")
 
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
 
int n, k1, k2, m, sz[MAXN], max_depth, cnt1SZ, cnt2SZ;
vector<int> g[MAXN];
bool ok[MAXN];
 
ll ans, sum1, sum2;
ll cnt1[MAXN], cnt2[MAXN];
 
void subtree_sz(int u, int p=-1, int cur = 0){
	sz[u]=1;
	max_depth = max(max_depth, cur);
 
	for(int v : g[u]) if(v != p && !ok[v]){
		subtree_sz(v,u,cur+1);
		sz[u] += sz[v];
	}
}
int find_centroid(int u, int p=-1){
	for(int v : g[u]) if(v != p && !ok[v]){
		if(sz[v]*2 > m) return find_centroid(v,u);	
	}
	return u;
}
 
ll add(int u, int cur=1, int p=-1, ll acc=0){
	if(cur >= cnt1SZ+1) return 0;
	ll ret = sum1 - sum2 - acc;
 
	if(cnt1SZ > k2-cur) acc += cnt1[k2-cur];
	if(cur <= k1 && cnt2SZ > k1-cur) acc -= cnt2[k1-cur];
 
	for(int v : g[u]) if(v != p && !ok[v]){
		ret += add(v, cur+1, u, acc);
	}
	return ret;
}
void upd(int u, int cur=1, int p=-1){
	if(cur >= cnt1SZ) return;
 
	cnt1[cur]++, sum1++;
	if(cnt2SZ > cur) cnt2[cur]++, sum2++;
 
	for(int v : g[u]) if(v != p && !ok[v]){
		upd(v, cur+1, u);	
	}
}
void solve(int u){
	max_depth = 0;
	subtree_sz(u);	
	m = sz[u];
 
	int c = find_centroid(u);
	ok[c]=true;
 
	cnt1SZ = min(k2, max_depth*2+1);
	cnt2SZ = min(k1, max_depth*2+1);
	cnt1[0] = cnt2[0] = 1;
	sum1 = 1;
	sum2 = (cnt2SZ > 0) ? 1 : 0; 
 
	fore(i,1,cnt1SZ) cnt1[i]=cnt2[i]=0;
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
	cin>>n>>k1>>k2;
	k1--;
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
