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
	vector<ll> st;int n;
    ll op(ll a, ll b){
        return a+b;
    }
	STree(int _n): st(_n*2,0),n(_n){}
	void build(){
		for(int i=n-1;i>0;i--)st[i]=op(st[i<<1],st[(i<<1)|1]);
	}
	void upd(int p, ll v){
		for(st[p+=n]+=v; p>>=1;)st[p]=op(st[p<<1],st[(p<<1)|1]);
	}
	ll query(int l, int r){
		ll resl=0,resr=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)resl=op(resl,st[l++]);
			if(r&1)resr=op(st[--r],resr);
		}
		return op(resl,resr);
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    ll x[n];
    forn(i,n) cin>>x[i];
    STree st(n+1);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            ll u;
            cin>>a>>b>>u;
            a--;
            st.upd(a,u);
            st.upd(b,-u);
        }
        else{
            int k;
            cin>>k;
            cout << x[k-1] + st.query(0,k) << "\n";
        }
    }
	return 0;
}
