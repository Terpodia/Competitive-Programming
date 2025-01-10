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

int n;
vector<int> g[MAXN];

pair<int,int> bfs(int s){
	vector<int> dist(n,-1);
	queue<int> q;
	q.push(s);
	dist[s]=0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : g[u]) if(dist[v] == -1){
			dist[v] = dist[u]+1;
			q.push(v);
		}
	}

	pair<int,int> ret = make_pair(s,0);
	forn(i,n) if(ret.snd < dist[i]){
		ret = make_pair(i,dist[i]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	pair<int,int> aux = bfs(0);
	cout << bfs(aux.fst).snd << "\n";
	return 0;
}

