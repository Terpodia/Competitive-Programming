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
    void upd(int k, int s, int e, int p, int v){
        if(s == e-1) st[k] += v;
        else{
            int m=(s+e)/2;
            if(p<m) upd(2*k,s,m,p,v);
            else upd(2*k+1,m,e,p,v);
            st[k] = op(st[2*k],st[2*k+1]);
        }
    }
	void upd(int p, int v){
		upd(1,0,n,p,v);
	}
    int get(int k, int s, int e, int v){
        if(s==e-1) return s;
        int m = (s+e)/2;
        if(st[2*k] >= v) return get(2*k, s, m, v);
        return get(2*k+1,m,e,v);
    }
    int get(int v){
        if(st[1] < v) return -1;
        return get(1,0,n,v);
    }
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin>>n>>m;
    int h[n];
    forn(i,n) cin>>h[i];
    STree st(n,h);
    forn(i,m){
        int r;
        cin>>r;
        int j = st.get(r);
        cout << j+1 << " ";
        if(j != -1) st.upd(j,-r);
    }
    cout << "\n";
    return 0;
}
