#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int k, b[2];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool check(ll pos) { return (k == 0 || (pos != b[0] && pos != b[k - 1])); }

int main() {
  fastIO();

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  cin >> k;
  for (int i = 0; i < k; i++) cin >> b[i];

  int dp[(1 << n)];
  dp[0] = 1;

  for (int i = 1; i < (1 << n); i++) {
    dp[i] = 0;
    int &acc = dp[i], sum = 0;

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        acc = acc + dp[i & (~(1 << j))];
        acc %= MOD;
        sum += a[j];
      }
    }

    if (!check(sum)) acc = 0;
  }

  cout << dp[(1 << n) - 1] << "\n";

  return 0;
}
