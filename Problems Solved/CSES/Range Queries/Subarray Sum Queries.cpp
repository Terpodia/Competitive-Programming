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

struct Vertex {
	ll sum, pref, suf, res;
};

struct STree {
	vector<Vertex> st;int n;
	Vertex op(Vertex a, Vertex b){
		Vertex ret;
		ret.sum = a.sum + b.sum;
		ret.pref = max(a.pref, a.sum + b.pref);
		ret.suf = max(b.suf, b.sum + a.suf);
		ret.res = max(a.res, b.res);
		ret.res = max(ret.res, a.suf + b.pref);
		return ret;
	}
	STree(int _n): st(_n*2),n(_n){
		forn(i,n*2) st[i] = {0,0,0,0};
	}
	void upd(int p, ll v){
		st[p+=n] = {v, max(0LL,v), max(0LL,v), max(0LL,v)};
		while(p>>=1)st[p]=op(st[p<<1],st[(p<<1)|1]);
	}
	ll query(int l, int r){
		Vertex resl = {0,0,0,0}, resr = {0,0,0,0};
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)resl=op(resl,st[l++]);
			if(r&1)resr=op(st[--r],resr);
		}
		return op(resl,resr).res;
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin>>n>>m;
	ll x[n];
	forn(i,n) cin>>x[i];
	STree st(n);
	forn(i,n) st.upd(i,x[i]);
	forn(i,m){
		int k;
		ll v;
		cin>>k>>v;
		st.upd(k-1,v);
		cout << st.query(0,n) << "\n";
	}
	return 0;
}

