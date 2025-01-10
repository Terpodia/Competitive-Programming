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

const ll P=1777771,MOD[2]={999727999,1070777777};

struct Node {
	ll fst, snd;
	int sz;
};

ll po[2][MAXN];

struct STree {
	vector<Node> st;int n;
	Node op(Node a, Node b){
		Node ret = a;
		ret.fst += (b.fst * po[0][a.sz]) % MOD[0];
		ret.snd += (b.snd * po[1][a.sz]) % MOD[1];
		ret.fst %= MOD[0], ret.snd %= MOD[1];
		ret.sz = a.sz + b.sz;
		return ret;
	}
	STree(int _n): st(_n*2),n(_n){
		forn(i,len(st)) st[i]={0,0,0};
	}
	STree(int _n, string& s): st(_n*2),n(_n){
		forn(i,n)st[n+i]={s[i], s[i], 1};
		build();
	}
	void build(){
		for(int i=n-1;i>0;i--)st[i]=op(st[i<<1],st[(i<<1)|1]);
	}
	void upd(int p, ll v){
		for(st[p+=n]={v,v,1}; p>>=1;)st[p]=op(st[p<<1],st[(p<<1)|1]);
	}
	ll query(int l, int r){
		Node resl = {0,0,0}, resr = {0,0,0};
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)resl=op(resl,st[l++]);
			if(r&1)resr=op(st[--r],resr);
		}
		Node res = op(resl,resr);
		return (res.fst << 32LL) | res.snd;
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	po[0][0] = po[1][0] = 1;
	fore(i,1,MAXN){
		po[0][i] = (po[0][i-1] * P) % MOD[0];
		po[1][i] = (po[1][i-1] * P) % MOD[1];
	}
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;

	string t = s;
	reverse(all(t));

	STree st1(n,s), st2(n,t);

	while(m--){
		int type;
		cin>>type;
		if(type == 1){
			int k;
			char x;
			cin>>k>>x;
			k--;
			st1.upd(k,x);
			st2.upd(n-k-1, x);
		}
		else{
			int l, r;
			cin>>l>>r;
			l--;
			if(st1.query(l, r) == st2.query(n-r, n-l)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}

	return 0;
}

