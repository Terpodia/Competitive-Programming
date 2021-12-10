#include <fstream>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e5+7, MAXK = 27;
int N, K, dp[MAXN][MAXK][3];
char a[MAXN];

int solve(int i, int k, int c){
    if(i==N) return 0;

    if(dp[i][k][c] != -1) return dp[i][k][c];
    int ret=0, add=0;
    
    if(c==0 && a[i] == 'S') add++;
    if(c==1 && a[i] == 'H') add++;
    if(c==2 && a[i] == 'P') add++;

    ret = solve(i+1, k, c) + add;

    if(k < K) ret = max(ret, max(solve(i+1,k+1,0)+add, max(solve(i+1,k+1, 1)+add, solve(i+1, k+1, 2)+add)));  

    return dp[i][k][c] = ret;
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    fin >> N >> K;
    for(int i=0; i<N; i++) fin >> a[i];
    
    fout << max(solve(0, 0, 0), max(solve(0, 0, 1), solve(0, 0, 2))) << "\n";

    return 0;
}
