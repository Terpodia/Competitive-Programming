#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

#define f first
#define s second

typedef pair<int, int> ii;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    ii points[m];
    for (int i = 0; i < m; i++) scanf("%d%d", &points[i].f, &points[i].s);
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++) mp[points[i].f] = i;

    sort(points, points + m,
         [](const ii& P1, const ii& P2) -> bool { return P1.s < P2.s; });

    int acc = 0, a[n * 2];
    for (int i = 0; i < n * 2; i++) a[i] = points[i].f, acc += points[i].s;

    sort(a, a + (n * 2));
    printf("%d\n", acc);
    int l = 0, r = (n * 2) - 1;
    while (r > l) {
      printf("%d %d\n", mp[a[l]] + 1, mp[a[r]] + 1);
      l++, r--;
    }
    puts("");
  }
  return 0;
}

