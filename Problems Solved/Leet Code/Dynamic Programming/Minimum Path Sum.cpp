#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int solve(vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size(); 
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    dp[1][1] = grid[0][0];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] != INF) continue;
            dp[i][j] = min(dp[i-1][j] + grid[i-1][j-1], dp[i][j-1] + grid[i-1][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    int n, m; scanf("%d%d",&n,&m);
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&grid[i][j]);

    printf("%d\n", solve(grid));
    return 0;
}
