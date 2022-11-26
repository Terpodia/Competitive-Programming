#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k % 4 == 0)
      puts("NO");
    else {
      puts("YES");
      if (k % 4 == 1) {
        for (int i = 1; i <= n && i + 2 <= n; i++)
          if (i % 4 != 0 && (i + 1) % 4 != 0) {
            if ((i + 2) % 4 == 0)
              printf("%d %d\n", i, i + 2);
            else
              printf("%d %d\n", i + 2, i);
          }
        if (n % 4 != 0) printf("%d %d\n", n - 1, n);
      } else {
        queue<int> q;
        for (int i = 1; i <= n; i++)
          if (i % 4 == 0 || (i + k) % 4 == 0) q.push(i);

        for (int i = 1; i <= n; i++)
          if (i % 4 != 0 && (i + k) % 4 != 0) {
            if (q.front() % 4 == 0)
              printf("%d %d\n", i, q.front());
            else
              printf("%d %d\n", q.front(), i);
            q.pop();
          }
      }
    }
  }
  return 0;
}
