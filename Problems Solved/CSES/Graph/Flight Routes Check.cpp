/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define all(cont) cont.begin(), cont.end()
#define pb push_back

const int MAXN = 1e5;
int n, m; 
vector<int> G[MAXN], RG[MAXN], SCC[MAXN]; 
vector<bool> vis(MAXN);
stack<int> s;

void fastIO(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
}

void DFS(int node){
    vis[node] = true;
    for(int i : RG[node]){
        if(!vis[i]) DFS(i);
    }
    s.push(node);
}

void findSCC(int node, int i){
	vis[node] = true;
	SCC[i].pb(node);
	for(int j : G[node]) if(!vis[j]) findSCC(j, i);
}

int main(){
	fastIO(); 
	cin >> n >> m;
	
	vis.resize(n, false);
	
	forn(i, 0, m){
        int u,v; cin >> u >> v;
        G[u-1].pb(v-1); RG[v-1].pb(u-1);
	}
	
	forn(i, 0, n) if(!vis[i]) DFS(i);
	
	fill(all(vis), false);
	
	int i=0;

	while(!s.empty()){
		int v = s.top(); s.pop();
		if(!vis[v]) { findSCC(v, i); i++; }
	}

	if(i > 1){
		cout << "NO\n";
		cout << SCC[0][0]+1 << " " << SCC[1][0]+1 << endl;
	}
	
	else cout << "YES\n" << endl;


	return 0;
}
