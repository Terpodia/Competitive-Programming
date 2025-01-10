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

const int MAXN = 5e4;

vector<int> g[2][MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin>>n>>m;
	vector<int> in(n,0), ans(n,0);
	forn(i,m){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[0][u].pb(v);
		g[1][v].pb(u);
		in[u]++;
	}
	queue<int> q;
	bitset<MAXN> s[n];
	forn(i,n) s[i].set(i,1);
	forn(i,n) if(in[i]==0) q.push(i);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans[u] = s[u].count();
		
		for(int v : g[1][u]){
			s[v] |= s[u];
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}

	forn(i,n) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}

