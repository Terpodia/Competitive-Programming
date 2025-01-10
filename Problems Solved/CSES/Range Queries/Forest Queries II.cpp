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

const int MAXN = 1000;

int st[MAXN * 4][MAXN * 4], x[MAXN][MAXN], n;


int op(int x, int y) { return x+y; }

void build_y(int k, int s, int e, int v, int l, int r){
	if(l+1 == r){
		if(s+1 == e) st[k][v] = x[s][l];
		else st[k][v] = op(st[2*k][v], st[2*k+1][v]);
		return;
	}
	int m = (l+r)/2;
	build_y(k, s, e, v*2, l, m);
	build_y(k, s, e, v*2+1, m, r);
	st[k][v] = op(st[k][2*v], st[k][2*v+1]);
}
void build_x(int k, int s, int e){
	if(s+1 == e) build_y(k, s, e, 1, 0, n);
	else{
		int m = (s+e)/2;
		build_x(k*2,s,m);
		build_x(k*2+1,m,e);
		build_y(k, s, e, 1, 0, n);
	}
}
void build(){
	build_x(1,0,n);
}

int query_y(int v, int l, int r, int k, int c, int d){
	if(l >= d || r <= c) return 0;
	if(l >= c && r <= d) return st[k][v];
	int m = (l+r)/2;
	int ans = query_y(v*2, l, m, k, c, d);
	ans = op(ans, query_y(v*2+1, m, r, k, c, d));
	return ans;
}
int query_x(int k, int s, int e, int a, int b, int c, int d){
	if(s >= b || e <= a) return 0;
	if(s >= a && e <= b) return query_y(1, 0, n, k, c, d);
	int m = (s+e)/2;
	int ans = query_x(2*k, s, m, a, b, c, d);
	ans = op(ans, query_x(2*k+1, m, e, a, b, c, d));
	return ans;
}
int query(int a, int b, int c, int d){
	return query_x(1, 0, n, a, b, c, d);
}

void upd_y(int k, int s, int e, int v, int l, int r, int i, int j){
	if(l+1 == r){
		if(s+1 == e) st[k][v] = 1 - st[k][v];
		else st[k][v] = op(st[2*k][v], st[2*k+1][v]);
		return;
	}
	int m = (l+r)/2;
	if(j < m) upd_y(k,s,e,v*2,l,m,i,j);
	else upd_y(k,s,e,v*2+1,m,r,i,j);
	st[k][v] = op(st[k][2*v], st[k][2*v+1]);
}
void upd_x(int k, int s, int e, int i, int j){
	if(s+1 == e) upd_y(k, s, e, 1, 0, n, i, j);
	else{
		int m = (s+e)/2;
		if(i < m) upd_x(2*k, s, m, i, j);
		else upd_x(2*k+1, m, e, i, j);
		upd_y(k, s, e, 1, 0, n, i, j);
	}
}
void upd(int i, int j){
	upd_x(1, 0, n, i, j);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
	cin>>n>>q;
	forn(i,n) forn(j,n){
		char c;
		cin>>c;
		if(c == '.') x[i][j] = 0;
		else x[i][j] = 1;
	}
	build();
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int i, j;
			cin>>i>>j;
			i--, j--;
			upd(i, j);
		}
		else{
			int a,b,c,d;
			cin>>a>>c>>b>>d;
			a--, c--;
			cout << query(a,b,c,d) << "\n";
		}
	}
	return 0;
}

