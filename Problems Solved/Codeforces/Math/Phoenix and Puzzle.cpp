#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n % 2 != 0 && n % 4 != 0)
      puts("NO");
    else {
      bool can = false;
      if (n % 2 == 0) {
        int f = floor(sqrt(n / 2)), c = ceil(sqrt(n / 2));
        if (f == c) can = true;
      }

      if (n % 4 == 0 && !can) {
        int f = floor(sqrt(n / 4)), c = ceil(sqrt(n / 4));
        if (f == c) can = true;
      }

      if (!can)
        puts("NO");
      else
        puts("YES");
    }
  }

  return 0;
}
