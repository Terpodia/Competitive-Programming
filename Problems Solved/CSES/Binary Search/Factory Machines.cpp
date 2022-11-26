#include <iostream>
using namespace std;

const int MAXN = 2 * 1e5;
int n;
long long t, k[MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

bool f(long long time) {
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += time / k[i];
    if (cnt >= t) return true;
  }
  return false;
}

long long bs() {
  long long lo = 0, hi = 1e18 + 3, mid;

  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main() {
  fastIO();
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> k[i];
  cout << bs() << "\n";
}
