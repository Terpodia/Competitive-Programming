#include <algorithm>
#include <iostream>
using namespace std;
int aux;

typedef long long ll;
typedef unsigned long long u64;

u64 k, x;

u64 bs() {
  u64 l = 0, r = 2 * k - 1;

  while (r > l) {
    u64 mid = l + (r - l) / 2;
    u64 y = min(k, mid);
    u64 w = (mid > k) ? mid - k : 0;

    u64 acc = (y * (y + 1)) / 2;

    if (mid > k) acc += ((k - 1 + k - w) * w) / 2;

    if (acc >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    cin >> k >> x;

    // u64 s1 = (k * (k+1)) / 2;
    // u64 s2 = ((k-1) * (k)) / 2;

    // u64 ans = ((x / (s1 + s2)) * (2 * k - 1)) + bs(x % (s1 + s2));

    cout << bs() << "\n";
  }

  return 0;
}
