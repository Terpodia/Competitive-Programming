#include <iostream>
using namespace std;
int aux;

typedef unsigned long long u64;

const int MAXN = 101;
const u64 INF = 1e18;

int n;
u64 h, a[MAXN];

bool can(u64 k) {
  u64 cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      cnt += k;
    else {
      if (a[i] + k - 1 < a[i + 1])
        cnt += k;
      else
        cnt += a[i + 1] - a[i];
    }

    if (cnt >= h) return true;
  }

  return false;
}

u64 solve() {
  u64 l = 1, r = INF;
  while (r > l) {
    u64 mid = l + (r - l) / 2;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }

  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << solve() << "\n";
  }

  return 0;
}
