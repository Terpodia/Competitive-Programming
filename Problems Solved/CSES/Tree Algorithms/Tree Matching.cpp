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

const int MAXN = 2e5 + 10;

vector<int> g[MAXN];

int dp[MAXN][2];

int solve(int u, int flag, int p=-1){
	int& ret = dp[u][flag];
	if(ret != -1) return ret;
	ret=0;

	if(flag==0){
		int acc=0;
		for(int v : g[u]) if(v != p){
			acc += solve(v,0,u);
		}
		ret=acc;
		for(int v : g[u]) if(v != p){
			ret=max(ret, acc-solve(v,0,u)+solve(v,1,u)+1);
		}
	}
	else{
		for(int v : g[u]) if(v != p){
			ret += solve(v,0,u);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(dp,-1,sizeof(dp));
	cout << solve(0,0) << "\n";
	return 0;
}

