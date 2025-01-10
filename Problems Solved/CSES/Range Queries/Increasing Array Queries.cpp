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
 
const int INF = 1e9+10;
 
#define op max
#define NEUT -INF
 
struct STree {
	vector<int> st;int n;
	STree(int _n, int *a): st(_n*4,NEUT),n(_n){
		build(1,0,n,a);
	}
	void build(int k, int s, int e, int *a){
		if(s == e-1) st[k] = a[s];
        else{
            int m=(s+e)/2;
            build(2*k,s,m,a);
            build(2*k+1,m,e,a);
            st[k] = op(st[2*k],st[2*k+1]);
        }
	}
	int query(int a, int b){
		return query(1,0,n,a,b);
	}
	int query(int k, int s, int e, int a, int b){
		if(s >= b || e <= a) return NEUT;
		if(s >= a && e <= b) return st[k];
		int m = (s+e)/2;
		return op(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	int calc(int k, int s, int e, int v){
		if(st[k] < v) return n;

        if(s==e-1) return s;
        int m = (s+e)/2;
        if(st[2*k] >= v) return calc(2*k, s, m, v);
        return calc(2*k+1,m,e,v);
	}
    int get(int k, int s, int e, int v, int a, int b){
		if(s >= b || e <= a) return n;
		if(s >= a && e <= b) return calc(k,s,e,v);	

        int m = (s+e)/2;
		int ans = get(2*k,s,m,v,a,b);
		if(ans == n) ans = get(2*k+1,m,e,v,a,b);
		return ans;
    }
    int get(int v, int a, int b){
		if(a >= b) return n;
        return get(1,0,n,v,a,b);
    }
};
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, q;
	cin>>n>>q;
	int x[n];
	forn(i,n) cin>>x[i];
	STree st(n,x);
	vector<ll> suff(n+1,0), pref(n+1,0);
	fore(i,1,n+1) pref[i]=pref[i-1]+(ll)(x[i-1]);
	dfor(i,n){
		int j = st.get(x[i], i+1, n);
		suff[i] = (ll)x[i] * (ll)(j-i) + suff[j];
	}
	while(q--){
		int l, r;
		cin>>l>>r;
		l--, r--;
		ll ans = suff[l];
		ll y = st.query(l,r+1);
		int j = st.get(y, r, n);
		ans -= y * (ll)(j-r-1) + suff[j];
		ll sum = pref[r+1]-pref[l];
		cout << ans-sum << "\n";
	}
    return 0;
}

