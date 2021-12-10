#include <iostream>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
int solve(int n, int k, vvi &dp) {
 
  if (dp[n][k] != -1)
    return dp[n][k];
 
  if (n == 0)
    return dp[n][k] = 0;
 
  if (k == 0)
    return dp[n][k] = 1;
 
  int suma = 0;
 
  for (int i = 0; i < n && k - i >= 0; ++i) {
 
    suma += solve(n - 1, k - i, dp);
  }
 
  return dp[n][k] = suma;
}
 
int main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int d, n, k;
 
  cin >> d;
 
  for (int i = 0; i < d; ++i) {
 
    cin >> n >> k;
 
    vvi dp(n + 10, vi(k + 10, -1));
 
    cout << solve(n, k, dp) << "\n";
  }
 
  return 0;
} 

