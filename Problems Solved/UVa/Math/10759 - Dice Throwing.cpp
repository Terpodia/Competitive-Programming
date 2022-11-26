#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef long long ll;

int n, x;
ll dp[25][151];

ll solve(int i, int cnt) {
  if (i == n) return (cnt >= x) ? 1 : 0;
  ll& ret = dp[i][cnt];
  if (ret != -1) return ret;
  ret = 0;
  for (int j = 1; j < 7; j++) ret += solve(i + 1, cnt + j);
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (cin >> n >> x && !(n == 0 && x == 0)) {
    memset(dp, -1, sizeof(dp));
    u64 den = 1, num;
    for (int i = 0; i < n; i++) den *= (u64)6;
    num = (u64)solve(0, 0);
    if (num == 0)
      cout << "0\n";
    else {
      u64 g = __gcd(num, den);
      num /= g, den /= g;
      if (den == 1)
        cout << num << "\n";
      else
        cout << num << "/" << den << "\n";
    }
  }
  return 0;
}
