// https://www.spoj.com/problems/EDIST/

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rep(i,x,n) for(__typeof(n) i=(x); i!=(n); i+=1-2*((x)>(n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line(x) cout << "\n=================================\n";

const int INF = 1e9;

string A, B;
int dp[2001][2001];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> A >> B;
    rep(i,0,sz(A)+1) dp[i][0] = i;
    rep(i,0,sz(B)+1) dp[0][i] = i;
    rep(i,1,sz(A)+1) rep(j,1,sz(B)+1) {
      dp[i][j] = INF;
      if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
      dp[i][j] = min(dp[i][j], 1+dp[i-1][j]); 
      dp[i][j] = min(dp[i][j], 1+dp[i][j-1]);
      dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
    }
    cout << dp[sz(A)][sz(B)] << "\n";
  }
  return 0;
}

