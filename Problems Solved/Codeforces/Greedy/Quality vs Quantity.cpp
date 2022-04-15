#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    sort(a, a + n);
    ll s1 = a[n - 1], s2 = a[0] + a[1];

    int i = 2, j = n - 2;

    while (i < j && s1 <= s2) {
      s1 += a[j], s2 += a[i];
      i++, j--;
    }

    printf("%s\n", (s1 > s2) ? "YES" : "NO");
  }
  return 0;
}

