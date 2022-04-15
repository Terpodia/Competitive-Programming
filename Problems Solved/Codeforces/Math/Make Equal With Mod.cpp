#include <algorithm>
#include <cstdio>
using namespace std;

bool can(int a[], int n) {
  bool areEqual = true;
  for (int i = 0; i < n - 1; i++)
    if (a[i] != a[i + 1]) areEqual = false;

  if (areEqual) return true;

  bool hasOne = false, hasZero = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      hasZero = true;
    else if (a[i] == 1)
      hasOne = true;
  }
  if (!hasOne) return true;
  if (hasOne && hasZero) return false;

  sort(a, a + n);
  for (int i = 0; i < n - 1; i++)
    if (a[i + 1] - a[i] == 1) return false;

  return true;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    printf("%s\n", (can(a, n)) ? "YES" : "NO");
  }
  return 0;
}

