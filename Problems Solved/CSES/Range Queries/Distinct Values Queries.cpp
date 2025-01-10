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

struct STree {
	vector<int> st;int n;
	STree(int _n): st(_n*2,0),n(_n){}
	int op(int a, int b) { return a+b; }
	void upd(int p, int v){
		for(st[p+=n]=v; p>>=1;)st[p]=op(st[p<<1],st[(p<<1)|1]);
	}
	int query(int l, int r){
		int resl=0,resr=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)resl=op(resl,st[l++]);
			if(r&1)resr=op(st[--r],resr);
		}
		return op(resl,resr);
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, q;
	cin>>n>>q;
	int x[n];
	forn(i,n) cin>>x[i];
	map<int,vector<int>> pos;
	
	forn(i,n) pos[x[i]].pb(i);

	tuple<int,int,int> queries[q];

	forn(i,q){
		int l, r;
		cin>>l>>r;
		auto &[s,e,idx] = queries[i];
		idx=i, s=l, e=r;
	}
	STree st(n);

	for(auto &[v,p] : pos) st.upd(p[0],1);

	vector<int> ans(q,-1);
	sort(queries,queries+q);

	int cur=0;

	forn(i,q){
		auto &[l,r,idx] = queries[i];
		l--;
		while(cur < l){
			auto it = upper_bound(all(pos[x[cur]]), cur);
			if(it != pos[x[cur]].end()) st.upd(*it, 1);
			cur++;
		}
		ans[idx] = st.query(l,r);
	}
	for(int i : ans) cout << i << "\n";
	return 0;
}

