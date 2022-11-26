#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 30;
int n, P, Q;
int a[MAXN];

void solve() {
  int ans = 0;
  int w = 0;

  for (int i = 0; i < n; i++) {
    if (w + a[i] > Q)
      break;
    else {
      ans++;
      w += a[i];
    }
  }
  printf("%d\n", min(ans, P));
}
int main() {
  int T;
  scanf("%d", &T);
  int testCase = 1;

  while (T--) {
    scanf("%d%d%d", &n, &P, &Q);
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    printf("Case %d: ", testCase);
    solve();
    testCase++;
  }

  return 0;
}
