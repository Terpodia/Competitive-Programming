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

#define mem(a, b) memset(a, (b), sizeof(a))
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define endl "\n"

const ll INF = 1e18, MOD = 1e9+7, MAXN = 20;
int n, m; ll dp[MAXN][1<<20];
vector<int> G[MAXN];

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

ll solve(int i, int msk){
	msk |= 1<<i;
	ll& ret = dp[i][msk];
	if(i==n-1 && __builtin_popcount(msk) != n) return ret = 0;
	if(i == n-1) return ret = 1;
	if(ret != -1) return ret;
	
	ret = 0;
	
	for(int j : G[i])
		if((msk & (1<<j)) == 0) ret = (ret + solve(j, msk)) % MOD;
	
	return ret;
}

int main(){
	mem(dp, -1);
    fastIO(); 
    cin >> n >> m;
    forn(i, 0, m){
		int u,v; cin >> u >> v;
		G[u-1].pb(v-1);
	}
	
	cout << solve(0, 0) << endl;

    return 0;
}
