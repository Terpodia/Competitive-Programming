#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    int cnt = 1;

    while (n > 0) {
      if (n % 10 > 0) v.push_back((n % 10) * cnt);
      n /= 10;
      cnt *= 10;
    }
    printf("%d\n", (int)v.size());
    for (int a : v) printf("%d ", a);
    puts("");
  }
  return 0;
}

