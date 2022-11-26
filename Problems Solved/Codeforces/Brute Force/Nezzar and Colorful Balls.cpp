#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    int m = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) mp[a[i]]++;

    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (m < it->second) {
        m += it->second - m;
      }
    }
    printf("%d\n", m);
  }

  return 0;
}
