#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int aux;

const int MAXN = 2e5, INF = 1e9;

int a[MAXN], n;

bool check(int p = -1) {
  int l = 0, r = n - 1;

  while (r > l) {
    if (a[l] != a[r]) {
      if (a[l] == p)
        l++;
      else if (a[r] == p)
        r--;
      else
        return false;
    } else
      l++, r--;
  }

  return true;
}

int main() {
  int t;
  aux = scanf("%d", &t);

  while (t--) {
    aux = scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      aux = scanf("%d", a + i);
    }

    if (check())
      puts("YES");
    else {
      int l = 0, r = n - 1;
      while (r > l) {
        if (a[l] != a[r]) break;
        l++, r--;
      }
      if (check(a[l]) || check(a[r]))
        puts("YES");
      else
        puts("NO");
    }
  }

  return 0;
}
