#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 2 * 1e5;
int n, x, p[MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int solve() {
  int res = 0;

  int a = 0, b = n - 1;

  while (a <= b) {
    if (a == b) {
      res++;
      break;
    }

    if (p[a] + p[b] <= x) {
      a++;
      b--;
      res++;
    } else {
      b--;
      res++;
    }
  }

  return res;
}

int main() {
  fastIO();
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> p[i];

  sort(p, p + n);
  cout << solve() << "\n";

  return 0;
}
