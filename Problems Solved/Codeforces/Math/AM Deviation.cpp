#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int aux;

const int INF = 1e9;

int bs1(int a1, int a2, int a3) {
  int lo = -1, hi = 1e8 + 1;

  int ans = INF;

  while (hi > lo) {
    int mid = lo + (hi - lo + 1) / 2;
    ans = min(ans, abs((a1 + a3 + mid) - (a2 - mid) * 2));

    if ((a2 - mid) * 2 >= (a1 + a3 + mid))
      lo = mid;
    else
      hi = mid - 1;
  }

  return ans;
}

int bs2(int a1, int a2, int a3) {
  int lo = -1, hi = 1e8 + 1;

  int ans = INF;

  while (hi > lo) {
    int mid = lo + (hi - lo + 1) / 2;
    ans = min(ans, abs((a1 + a3 - mid) - (a2 + mid) * 2));

    if ((a2 + mid) * 2 <= (a1 + a3 - mid))
      lo = mid;
    else
      hi = mid - 1;
  }

  return ans;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int a1, a2, a3;
    aux = scanf("%d%d%d", &a1, &a2, &a3);

    printf("%d\n", ((a2 * 2) > a1 + a3) ? bs1(a1, a2, a3) : bs2(a1, a2, a3));
  }

  return 0;
}
