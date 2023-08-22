#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int n;
ll p[20];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
}

ll solve(int i, ll cnt1, ll cnt2) {
  if (i == n) return abs(cnt1 - cnt2);

  return min(solve(i + 1, cnt1 + p[i], cnt2), solve(i + 1, cnt1, cnt2 + p[i]));
}

int main() {
  fastIO();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];

  cout << solve(0, 0, 0) << "\n";

  return 0;
}
