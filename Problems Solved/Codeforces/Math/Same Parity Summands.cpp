#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);

    if (n % 2 == 0) {
      if ((k - 1) * 2 < n) {
        puts("YES");
        for (int i = 0; i < k - 1; i++) printf("2 ");
        printf("%d\n", n - (k - 1) * 2);
      }

      else if (k - 1 < n && (n - k + 1) % 2 != 0) {
        puts("YES");
        for (int i = 0; i < k - 1; i++) printf("1 ");
        printf("%d\n", n - k + 1);
      }

      else
        puts("NO");
    }

    else {
      if (k - 1 >= n || (n - k + 1) % 2 == 0)
        puts("NO");
      else {
        puts("YES");
        for (int i = 0; i < k - 1; i++) printf("1 ");
        printf("%d\n", n - k + 1);
      }
    }
  }
  return 0;
}
