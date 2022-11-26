#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef pair<int, int> ii;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

const int INF = 1e9;

int n, l[300], c[300], aux;
map<ii, int> dp;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int solve(int i, int acc) {
  if (i == n) return (acc == 1) ? 0 : INF;
  if (dp.find({i, acc}) != dp.end()) return dp[{i, acc}];
  return dp[{i, acc}] =
             min(solve(i + 1, acc), c[i] + solve(i + 1, gcd(acc, l[i])));
}

int main() {
  aux = scanf("%d", &n);
  FOR(i, 0, n) aux = scanf("%d", l + i);
  FOR(i, 0, n) aux = scanf("%d", c + i);

  int acc = 0;
  FOR(i, 0, n) acc = gcd(acc, l[i]);

  printf("%d\n", (acc != 1) ? -1 : solve(0, 0));

  return 0;
}
