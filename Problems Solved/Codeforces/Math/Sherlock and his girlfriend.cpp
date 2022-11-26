#include <cstdio>
#include <cstring>

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  int c[n + 7];
  memset(c, 0, sizeof(c));

  if (n == 1) {
    puts("1");
    puts("1");
    return 0;
  }

  if (n == 2) {
    puts("1");
    puts("1 1");
    return 0;
  }

  c[2] = 1;
  for (int i = 4; i < (n + 7); i += 2) c[i] = 2;

  for (int i = 3; i < (n + 7); i += 2) {
    if (c[i] == 0) {
      c[i] = 1;
      if ((ll)i * (ll)i > (ll)(n + 7)) continue;
      for (int j = i * i; j < (n + 7); j += i) c[j] = 2;
    }
  }

  puts("2");
  for (int i = 2; i <= (n + 1); i++) printf("%d ", c[i]);
  puts("");

  return 0;
}
