#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x;
    scanf("%d", &x);

    vector<int> ans(31, 0);

    for (int i = 0; i < 30; i++)
      if (x & (1 << i)) {
        if (i > 0 && ans[i - 1] != 0)
          ans[i - 1] = -1, ans[i] = 0, ans[i + 1] = 1;
        else if (ans[i] == 1)
          ans[i] = 0, ans[i + 1] = 1;
        else
          ans[i] = 1;
      }

    puts("31");
    for (int i = 0; i < 31; i++) printf("%d%c", ans[i], " \n"[i == 30]);
  }
  return 0;
}
