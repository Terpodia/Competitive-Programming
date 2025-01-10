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

int n, q, p[MAXN], anc[MAXN][23];
vector<int> g[MAXN];

void dfs(int u){
	anc[u][0] = p[u];
	fore(i,1,23){
		if(anc[u][i-1] == -1) break;
		anc[u][i] = anc[anc[u][i-1]][i-1];
	}
	for(int v : g[u]) if(v != p[u]){
		dfs(v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	memset(p,-1,sizeof(p));
	memset(anc,-1,sizeof(anc));

	cin>>n>>q;
	forn(i,n-1){
		cin>>p[i+1];
		p[i+1]--;
		g[p[i+1]].pb(i+1);
		g[i+1].pb(p[i+1]);
	}
	dfs(0);

	while(q--){
		int u,k;
		cin>>u>>k;
		u--;	

		int res = u;
		dfor(i,23){
			if(res == -1) break;

			int x = 1<<i;
			if(k - x >= 0){
				res = anc[res][i];
				k -= x;
			}
		}
		if(res != -1) cout << res+1 << "\n";
		else cout << "-1\n";
	}
	return 0;
}

