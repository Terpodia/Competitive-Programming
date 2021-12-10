#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int X, Y, K, M;

int dp[107][107][107];

int solve(int k, int x, int y){
    int& ret = dp[k][x][y];
    if(k > K) return ret = abs(M - (x+y)); 

    if(ret != -1) return ret;

    ret = min(solve(k+1, X, y), solve(k+1, x, Y));
    ret = min(ret, min(solve(k+1, 0, y), solve(k+1, x, 0)));
    int rx = X - x, ry = Y - y;
    
    ret = min(ret, solve(k+1, max(x-ry, 0), min(y+x, Y)));
    ret = min(ret, solve(k+1, min(x+y, X), max(y-rx, 0)));

    return ret;
}

int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    
    memset(dp, -1, sizeof(dp));
    
    fin >> X >> Y >> K >> M;

    fout << solve(1, 0, 0) << "\n";

    return 0;
}
