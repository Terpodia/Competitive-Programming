#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 2e5;
ll a[MAXN], b[MAXN], k;
int n, m;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void solve() {
  sort(a, a + n);
  sort(b, b + m);

  int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= k) {
      ans++;
      i++;
      j++;
    } else {
      if (a[i] < b[j])
        i++;
      else
        j++;
    }
  }

  cout << ans << "\n";
}

int main() {
  fastIO();
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  solve();

  return 0;
}
