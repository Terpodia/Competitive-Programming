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

#define NEUT 0

struct STree {
	vector<ll> st;int n;
	ll op(ll x, ll y) { return x+y; }
	STree(int _n): st(_n*2,NEUT),n(_n){}
	STree(int _n, ll *a): st(_n*2,NEUT),n(_n){
		fore(i,0,n)st[n+i]=a[i];
		build();
	}
	void build(){
		for(int i=n-1;i>0;i--)st[i]=op(st[i<<1],st[(i<<1)|1]);
	}
	void upd(int p, ll v){
		for(st[p+=n]=v; p>>=1;)st[p]=op(st[p<<1],st[(p<<1)|1]);
	}
	ll query(int l, int r){
		ll resl=NEUT,resr=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)resl=op(resl,st[l++]);
			if(r&1)resr=op(st[--r],resr);
		}
		return op(resl,resr);
	}
};


int n, q;
ll val[MAXN];
vector<int> g[MAXN];
int cur, pos[MAXN], ls[MAXN];

void dfs(int u, int p=-1){
	pos[u] = cur++;
	for(int v : g[u]) if(v != p){
		dfs(v,u);
	}
	ls[u] = cur;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	forn(i,n) cin>>val[i];
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);

	ll a[n];
	forn(i,n) a[pos[i]] = val[i];
	STree st(n,a);

	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int u;
			ll x;
			cin>>u>>x;
			u--;
			st.upd(pos[u], x);
		}
		else{
			int u;
			cin>>u;
			u--;
			cout << st.query(pos[u], ls[u]) << "\n";
		}
	}
	return 0;
}

