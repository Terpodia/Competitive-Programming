#include <cstdio>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++) scanf("%d", c + i);
    bool can = true;
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (c[i] == 1 && p == -1)
        p = i;
      else if (c[i] == 1 && p != -1)
        can = false;
    }
    if (p == -1) can = false;

    if (can) {
      vector<int> d;
      for (int i = p; i < n; i++) d.push_back(c[i]);
      for (int i = 0; i < p; i++) d.push_back(c[i]);
      for (int i = 0; i < sz(d) - 1; i++)
        if (d[i] < d[i + 1] && d[i + 1] - d[i] > 1) can = false;
    }
    printf("%s\n", (can) ? "YES" : "NO");
  }
  return 0;
}
