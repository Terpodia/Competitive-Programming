#include "bits/stdc++.h"
using namespace std;

typedef long double ld;

ld dp[110][1000];
int n, a, b;

ld f(int i, int k) {
  if (i == n) {
    if (k >= a && k <= b) return 1;
    return 0;
  }
  ld& ret = dp[i][k];
  if (ret >= 0) return ret;
  ret = 0;
  for (int j = 1; j <= 6; j++) {
    ret += f(i + 1, k + j) * (ld)1 / (ld)6;
  }
  return ret;
}

int main() {
  cout << fixed << setprecision(6);
  for (int i = 0; i < 110; i++) {
    for (int j = 0; j < 1000; j++) {
      dp[i][j] = -1;
    }
  }
  cin >> n >> a >> b;
  cout << f(0, 0) << "\n";
  return 0;
}
