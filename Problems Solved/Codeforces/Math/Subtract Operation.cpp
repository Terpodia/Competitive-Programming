#include <cstdio>
#include <set>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(a[i]);
    bool can = false;
    for (int i = 0; i < n; i++) {
      can |= (s.find(a[i] - k) != s.end());
    }
    printf("%s\n", (can) ? "YES" : "NO");
  }
  return 0;
}
