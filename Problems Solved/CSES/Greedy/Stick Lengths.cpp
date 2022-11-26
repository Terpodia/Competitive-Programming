#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int main() {
  fastIO();
  int n;
  cin >> n;
  ll ans = 0, p[n];
  for (int i = 0; i < n; i++) cin >> p[i];

  sort(p, p + n);

  int pos = (n + 1) / 2 - 1;
  for (int i = 0; i < n; i++) ans += abs(p[i] - p[pos]);

  cout << ans << "\n";
  return 0;
}
