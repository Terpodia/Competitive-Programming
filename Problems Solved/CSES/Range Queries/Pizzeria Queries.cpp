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

const int INF = 1e9 + 10;

#define op min
#define NEUT INF

struct STree {
	vector<int> st;int n;
	STree(int _n): st(_n*2,NEUT),n(_n){}
	void upd(int p, int v){
		for(st[p+=n]=v; p>>=1;)st[p]=op(st[p<<1],st[(p<<1)|1]);
	}
	int query(int l, int r){
		int resl=NEUT,resr=NEUT;
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
	int p[n];
	forn(i,n) cin>>p[i];
	STree st1(n), st2(n);
	forn(i,n) st1.upd(i,p[i]+i);
	forn(i,n) st2.upd(i,p[i]+n-1-i);

	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int k, x;
			cin>>k>>x;
			k--;
			st1.upd(k,x+k);
			st2.upd(k,x+n-1-k);
		}
		else{
			int k;
			cin>>k;
			k--;
			int ans1 = st1.query(k,n) - k;
			int ans2 = st2.query(0,k) - (n-1-k);
			cout << min(ans1, ans2) << "\n";
		}
	}
	return 0;
}

