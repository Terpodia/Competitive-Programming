#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 1e5;
int a[MAXN], n;

void solve() {
  int pos = 0, x = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] < x) {
      pos = i;
      x = a[i];
    }

  printf("%d\n", n - 1);
  for (int i = 0; i < n; i++) {
    if (pos == i) continue;
    printf("%d %d %d %d\n", pos + 1, i + 1, x, x + abs(i - pos));
  }
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    solve();
  }

  return 0;
}
