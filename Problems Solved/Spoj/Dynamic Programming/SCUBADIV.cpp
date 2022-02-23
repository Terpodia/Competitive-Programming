#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
 
// t = oxigeno, a = nitrogeno
int t, a, n;
 
int solve(vi &T, vi &A, vi &W, int pos, int ox_act, int nitr_act, vvvi &dp) {
 
  ox_act = min(t, ox_act);
  nitr_act = min(a, nitr_act);
 
  if (pos == n - 1) {
 
    if (ox_act >= t && nitr_act >= a) {
 
      return dp[pos][ox_act][nitr_act] = 0;
    }
 
    if (ox_act + T[pos] >= t && nitr_act + A[pos] >= a) {
 
      return dp[pos][ox_act][nitr_act] = W[pos];
    }
 
    return 1e9;
  }
 
  if (dp[pos][ox_act][nitr_act] != -1) {
 
    return dp[pos][ox_act][nitr_act];
  }
 
  return dp[pos][ox_act][nitr_act] =
             min(W[pos] + solve(T, A, W, pos + 1, ox_act + T[pos],
                                nitr_act + A[pos], dp),
                 solve(T, A, W, pos + 1, ox_act, nitr_act, dp));
}
 
int main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int c;
 
  cin >> c;
 
  for (int i = 0; i < c; ++i) {
 
    cin >> t >> a;
 
    cin >> n;
 
    vi T(n), A(n), W(n);
 
    for (int j = 0; j < n; ++j) {
 
      cin >> T[j] >> A[j] >> W[j];
    }
 
    vvvi dp(1024, vvi(22, vi(80, -1)));
 
    cout << solve(T, A, W, 0, 0, 0, dp) << "\n";
  }
 
  return 0;
} 

