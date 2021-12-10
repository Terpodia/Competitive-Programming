/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define endl "\n"
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, (b), sizeof(a))
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back

const ll INF = 1e18, MOD = 1e9+7, MAXN = 1e5;
int N, M; vector<int> G[MAXN], v(MAXN);

void fastIO(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
}

void tc(){
	int t, ca = 1; cin >> t;
	while(t--){
		ca++;
	}
}

void solve(){
	vector<bool> vis(N, false);
	queue<pair<int,int>> Q;
	
	Q.push({0, -1}); vis[0] = true;
	while(!Q.empty()){
		pair<int,int> p = Q.front(); Q.pop();
		v[p.first] = p.second;
		
		for(int i : G[p.first]){
			if(!vis[i]){
				vis[i] = true; Q.push({i, p.first});
			}
		}
	}
	
	if(!vis[N-1]) cout << "IMPOSSIBLE\n";
	
	int k=0, i = N-1;
	vector<int> ans;
	
	while(i != -1){
		ans.pb(i); i = v[i];
		k++;
	}
	
	cout << k << endl;
	rforn(j, k-1, 0) cout << ans[j]+1 << " ";
	cout << endl;
}

int main(){
	fastIO(); 
    cin >> N >> M;
    forn(i, 0, M){
		int a,b; cin >> a >> b;
		G[a-1].pb(b-1); G[b-1].pb(a-1);
	}
	
	solve();

	return 0;
}
