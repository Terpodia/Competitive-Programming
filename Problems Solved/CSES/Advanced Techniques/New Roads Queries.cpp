#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

struct T {
	int u, v, idx;
};
struct State {
	int l, r;
	vector<T> q;
};
struct UnionFind {
	int n,comp;
	vector<int> uf,si;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;
		return true;
	}
};

int n;
vector<pair<int,int>> e;
vector<T> queries;

void solve(){
	queue<State> q;
	q.push({0, len(e)-1, queries});
	vector<int> ans(len(queries), -1);
	int lst = 0;
	UnionFind dsu(n);

	while(!q.empty()){
		auto [l,r,cur] = q.front();
		q.pop();
		assert(l<=r);

		int mid = l+(r-l)/2;
		if(lst > mid+1) lst=0, dsu = UnionFind(n);
		fore(i,lst,mid+1) dsu.join(e[i].fst, e[i].snd);
		lst=mid+1;
		if(l==r){
			for(auto [u,v,idx] : cur){
				if(dsu.find(u) == dsu.find(v)) ans[idx]=l+1;
				if(u==v) ans[idx]=0;
			}
			continue;
		}
		vector<T> left, right;
		for(auto [u,v,idx] : cur){
			if(dsu.find(u) == dsu.find(v)) left.pb({u,v,idx});
			else right.pb({u,v,idx});
		}
		if(len(left)) q.push({l, mid, left});
		if(len(right)) q.push({mid+1, r, right});
	}
	for(int i : ans) cout << i << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int m, q;
	cin>>n>>m>>q;
	forn(i,m){
		int u,v;
		cin>>u>>v;
		u--,v--;
		e.pb(make_pair(u,v));
	}
	forn(i,q){
		int u,v;
		cin>>u>>v;
		u--,v--;
		queries.pb({u,v,i});
	}
	solve();
	return 0;
}

