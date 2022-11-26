#include <bitset>
#include <cstdio>
using namespace std;

const int MAX = 8001 * 8001;

bitset<MAX> ck;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    ck.set();

    for (int i = 0; i < n; i++) {
      int sum = a[i];
      for (int j = i + 1; j < n; j++) {
        sum += a[j];
        ck[sum] = 0;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
      if (ck[a[i]] == 0) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
