#include <fstream>#include <algorithm>#include <vector>using namespace std;const int MAXN = 1007, INF = 1e9;int N, M, C, dp[MAXN][MAXN], m[MAXN];vector<int> G[MAXN];int solve(int i, int d){    if(d > 1000) return -INF;        int& ret = dp[i][d];       if(ret != -INF) return ret;    
    for(int j : G[i])
        ret = max(ret, m[j] + solve(j, d+1));        if(i == 0) ret = max(ret, -d*d*C);    return ret;}int main(){    for(int i=0; i<MAXN; i++) for(int j=0; j<MAXN; j++) dp[i][j] = -INF;    
	ifstream fin("time.in");	ofstream fout("time.out");	    fin >> N >> M >> C;        for(int i=0; i<N; i++) fin >> m[i];        for(int i=0; i<M; i++){
        int u,v ; fin >> u >> v;        G[u-1].push_back(v-1);
    }        fout << solve(0, 0) << "\n";		return 0;
}