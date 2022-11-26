#include <iostream>
#include <vector>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a.push_back(0);
    sort(a.begin(), a.end(), greater<int>());
    printf("%s\n", (a[0] - a[1] > 1) ? "NO" : "YES");
  }
  return 0;
}
