#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m, r;
    scanf("%d%d%d",&n,&m,&r);

    int dp[n][n][n];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                dp[i][j][k] = INF;

    for(int _=0; _<m; _++) {
        int a[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) scanf("%d",a[i]+j);

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dp[i][j][0] = min(dp[i][j][0], a[i][j]);
    }

    for(int c=1; c<n; c++) 
        for(int k=0; k<n; k++) 
            for(int i=0; i<n; i++) 
                for(int j=0; j<n; j++)
                    dp[i][j][c] = min(dp[i][j][c], dp[i][k][c-1] + dp[k][j][0]); 
        
    while(r--) {
        int s, t, k; scanf("%d%d%d",&s,&t,&k);
        k = min(k, n-1), s--, t--;
        printf("%d\n", dp[s][t][k]);
    }

    return 0;
}

