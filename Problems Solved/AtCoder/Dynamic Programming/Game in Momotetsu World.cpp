#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAXN = 2000, INF = 1e9;

int n, m; char a[MAXN][MAXN];
vector<vvi> dp(MAXN, vvi(MAXN, vi(2, -INF))); 

int calc(int i, int j, int p) {
    if(i >= n || j >= m) return (p == 0)? -INF : INF;

    int s;
    if(a[i][j] == '+') s = (p==0)? 1 : -1;
    else s = (p==0)? -1 : 1;
    
    return s;
}

int solve(int i, int j, int p) {
    if(i == n-1 && j == m-1) return 0;

    if(i >= n || j >= m) return 0;

    int& ret = dp[i][j][p];

    if(ret != -INF) return ret;

    int s1, s2;
    s1 = calc(i+1, j, p), s2 = calc(i, j+1, p);

    if(p == 0)
        return ret = max(s1 + solve(i+1, j, 1), s2 + solve(i, j+1, 1)); 
    
    return ret = min(s1 + solve(i+1, j, 0), s2 + solve(i, j+1, 0));
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c",&a[i][j]);

    int ans = solve(0, 0, 0);

    if(ans > 0) puts("Takahashi");
    else if(ans == 0) puts("Draw");
    else puts("Aoki");

    return 0;
}
