/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
#include <cstring>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i,x,n) for(int i=(x); i<(int)n; i++)

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int n, m, r[100], b[100];
int dp[200][200];

int solve(int i, int j) {
    if(i == n && j == m) return 0;
    int& ret = dp[i][j];
    
    if(ret != -1) return ret;

    ret=0;

    if(i < n) ret = max(ret, r[i] + solve(i+1, j));
    if(j < m) ret = max(ret, b[j] + solve(i, j+1));
    return ret;
}

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) {
        cin >> n;
        forn(i,0,n) cin >> r[i];
        cin >> m;
        forn(i,0,m) cin >> b[i];

        memset(dp, -1, sizeof(dp));
        cout << solve(0,0) << "\n";
    }

    return 0;
}

