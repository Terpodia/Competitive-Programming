#include <stdio.h>

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    bool flag = true;

    while (n % 2 == 0) {
      n /= (ll)2;
      if (n % 2 == 0 || n == 1)
        flag = false;
      else
        flag = true;
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
