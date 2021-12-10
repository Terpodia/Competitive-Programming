#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXT = 5e6, INF = 1e9;
int T, A, B, dp[MAXT][2];

int solve(int s, int c)
{
    if(s > T) return -INF; 

    int& ret = dp[s][c];
    if(ret != -1) return ret;
    ret = max(s, max(solve(s+A, c), solve(s+B, c)));

    if(c != 0) ret = max(ret, solve(s/2, 0));
    return ret;
}

int main(void)
{
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    fin >> T >> A >> B;
    memset(dp, -1, sizeof(dp));
    
    fout << solve(0, 1) << "\n";

    return 0;
}
