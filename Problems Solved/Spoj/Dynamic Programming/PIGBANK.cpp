#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int E, F, N;

int solve(vi &P, vi &W, vvi &dp, int pos, int peso_actual) {
  if (dp[pos][peso_actual] != -1) {
    return dp[pos][peso_actual];
  }

  if (pos == N - 1) {
    if (peso_actual < F) {
      return dp[pos][peso_actual] =
                 P[pos] + solve(P, W, dp, pos, peso_actual + W[pos]);
    }

    if (peso_actual == F) {
      return dp[pos][peso_actual] = 0;
    }

    return 1e9;
  }

  if (peso_actual == F) {
    return dp[pos][peso_actual] = 0;
  }

  if (peso_actual > F) {
    return 1e9;
  }

  return dp[pos][peso_actual] =
             min(P[pos] + solve(P, W, dp, pos, peso_actual + W[pos]),
                 solve(P, W, dp, pos + 1, peso_actual));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int ans, T;
  cin >> T;

  for (int i = 0; i < T; ++i) {
    cin >> E >> F;

    cin >> N;

    vi P(N), W(N);

    for (int j = 0; j < N; ++j) {
      cin >> P[j] >> W[j];
    }

    vvi dp(500, vi(1e5, -1));

    ans = solve(P, W, dp, 0, E);

    if (ans >= 1e9) {
      cout << "This is impossible.\n";
    }

    else {
      cout << "The minimum amount of money in the piggy-bank is " << ans
           << ".\n";
    }
  }

  return 0;
}
