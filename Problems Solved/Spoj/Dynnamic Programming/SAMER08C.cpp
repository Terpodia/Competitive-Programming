#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
int N, M;
 
int farida(vvi &candies, int i, int j, vvi &dp) {
 
  if (i < 0 || j < 0)
    return 0;
 
  if (dp[i][j] != -1) {
 
    return dp[i][j];
  }
 
  return dp[i][j] = max(candies[i][j] + farida(candies, i, j - 2, dp),
                        candies[i][j] + farida(candies, i, j - 3, dp));
}
 
int solve(vvi &candies, int i, int j, vvi &dp) {
 
  if (i < 0 || j < 0)
    return 0;
 
  if (dp[i][j] != -1) {
 
    return dp[i][j];
  }
 
  int aux = max(farida(candies, i, j, dp), farida(candies, i, j - 1, dp));
 
  return dp[i][j] = max(aux + solve(candies, i - 2, j, dp),
                        aux + solve(candies, i - 3, j, dp));
}
 
int main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  do {
 
    cin >> N >> M;
 
    if (N == 0 && M == 0) {
 
      break;
    }
 
    vvi candies(N, vi(M));
 
    for (int i = 0; i < N; ++i) {
 
      for (int j = 0; j < M; ++j) {
 
        cin >> candies[i][j];
      }
    }
 
    vvi dp(N, vi(M, -1));
 
    cout << max(solve(candies, N - 1, M - 1, dp),
                solve(candies, N - 2, M - 1, dp))
         << "\n";
 
  } while (N != 0 || M != 0);
 
  return 0;
} 

