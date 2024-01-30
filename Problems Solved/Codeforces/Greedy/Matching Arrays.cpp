#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, x;
    scanf("%d%d", &n, &x);
    pair<int, int> a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i].fst);
      a[i].snd = i;
    }
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    sort(a, a + n);
    sort(b, b + n);
    int cnt = 0, ans[n];

    for (int i = 0; i < n; i++) {
      ans[a[((i - x) % n + n) % n].snd] = b[i];
      if (a[((i - x) % n + n) % n].fst > b[i]) cnt++;
    }

    if (cnt != x)
      puts("NO");
    else {
      puts("YES");
      for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
  }
  return 0;
}
