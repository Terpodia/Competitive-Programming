#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = 31;

ll dp[MAXN][MAXN];

void setIO() { cin.tie(0)->sync_with_stdio(false); }

string solve(int A, int B, ll K) {
    if(A == 0 && B == 0) return "";
    if(A == 0) return "b" + solve(A, B-1, K);
    if(B == 0) return "a" + solve(A-1, B, K);

    return (dp[A-1][B] >= K)? "a" + solve(A-1, B, K) : "b" + solve(A, B-1, K - dp[A-1][B]);
}

int main() {
    setIO();
    int A, B; ll K;    
    cin >> A >> B >> K;

    for(int i=0; i<MAXN; i++) dp[0][i] = 1;
    for(int i=0; i<MAXN; i++) dp[i][0] = 1;

    for(int i=1; i<MAXN; i++) {
        for(int j=1; j<MAXN; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << solve(A, B, K) << "\n";

    return 0;
}
