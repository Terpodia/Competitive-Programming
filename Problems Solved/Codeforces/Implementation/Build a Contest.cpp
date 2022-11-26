#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[m];
  for (int i = 0; i < m; i++) scanf("%d", a + i);

  int cnt[n + 1], b[m + 1];
  memset(cnt, 0, sizeof(cnt));
  memset(b, 0, sizeof(b));

  int curr = 1;
  for (int i = 0; i < m; i++) {
    cnt[a[i]]++;
    b[cnt[a[i]]]++;

    if (b[curr] == n) {
      curr++;
      printf("1");
    } else
      printf("0");
  }
  puts("");
  return 0;
}
