#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, ans = 0;

    bool flag = false;
    while (!flag) {
      for (int i = 0; i < 9; i++) {
        a[i] *= 10;
        a[i] += i + 1;
        if (n >= a[i])
          ans++;
        else {
          flag = true;
          break;
        };
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
