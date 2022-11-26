#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5;

int n;
ll s, a[MAXN];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%lld", &n, &s);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    int l = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] >= 0 || abs(a[i]) <= s) {
        l = i;
        break;
      }
    }
    if (l == -1)
      puts("-1");
    else {
      ii p = {l, l};
      int cnt = 1, r = l + 1;
      ll acc = s + a[l];

      while (l < n && r < n) {
        if (acc + a[r] >= 0) {
          if (cnt < r - l + 1) {
            cnt = r - l + 1;
            p = {l, r};
          }
          acc += a[r];
          r++;
        }

        else if (acc + a[r] < 0 && l != r)
          acc -= a[l], l++;

        else
          l++, r++;
      }
      printf("%d %d\n", p.first + 1, p.second + 1);
    }
  }
  return 0;
}
