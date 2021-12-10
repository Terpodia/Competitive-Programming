#include <iostream>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
int n, k;
 
int solve(int pos, int cerrar_abrir, vi &brackets, vvi &dp) {
 
  if (pos == n * 2) {
 
    if (cerrar_abrir == 0) {
 
      return 1;
    }
 
    return 0;
  }
 
  if (dp[pos][cerrar_abrir] != -1) {
 
    return dp[pos][cerrar_abrir];
  }
 
  if (brackets[pos] != -1) {
 
    if (brackets[pos] == 0) {
 
      return dp[pos][cerrar_abrir] =
                 solve(pos + 1, cerrar_abrir - 1, brackets, dp);
    }
 
    return dp[pos][cerrar_abrir] =
               solve(pos + 1, cerrar_abrir + 1, brackets, dp);
  }
 
  if (cerrar_abrir == 0) {
 
    return dp[pos][cerrar_abrir] =
               solve(pos + 1, cerrar_abrir + 1, brackets, dp);
  }
 
  return dp[pos][cerrar_abrir] =
             solve(pos + 1, cerrar_abrir + 1, brackets, dp) +
             solve(pos + 1, cerrar_abrir - 1, brackets, dp);
}
 
int main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int c;
 
  cin >> c;
 
  for (int i = 0; i < c; ++i) {
 
    cin >> n >> k;
 
    vi open_brackets(k);
 
    // -1 = no hay corchetes, 0 = corchete cerrado, 1 = corchete abierto
    vi brackets(2 * n, -1);
    brackets[0] = 1;
 
    for (int j = 0; j < k; ++j) {
 
      cin >> open_brackets[j];
 
      brackets[open_brackets[j] - 1] = 1;
    }
 
    vvi dp(100, vi(500, -1));
 
    cout << solve(0, 0, brackets, dp) << "\n";
  }
 
  return 0;
} 

