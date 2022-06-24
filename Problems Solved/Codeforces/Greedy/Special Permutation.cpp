#include <cstdio>
#include <cstring>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if (n <= 3)
      puts("-1");
    else {
      bool ck[n + 1];
      memset(ck, false, sizeof(ck));
      for (int i = 2; i <= n; i += 2) {
        ck[i] = true;
        printf("%d ", i);
      }
      if (n % 2 == 0) {
        printf("%d ", n - 3);
        ck[n - 3] = true;
      } else {
        printf("%d ", n - 4);
        ck[n - 4] = true;
      }

      int j = (n % 2 == 0) ? n - 1 : n;
      for (int i = j; i > 0; i--) {
        if (ck[i]) continue;
        printf("%d ", i);
        ck[i] = true;
      }
      puts("");
    }
  }
  return 0;
}

