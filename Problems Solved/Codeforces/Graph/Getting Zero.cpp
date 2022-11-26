#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);

  int d[32768];
  memset(d, -1, sizeof(d));
  queue<int> q;
  q.push(0);
  d[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v1 = (u - 1 + 32768) % 32768, v2 = (u / 2);
    if (d[v1] == -1) {
      d[v1] = d[u] + 1;
      q.push(v1);
    }
    if (u % 2 == 0 && d[v2] == -1) {
      d[v2] = d[u] + 1;
      q.push(v2);
    }
    if (u % 2 == 0 && d[v2 + 32768 / 2] == -1) {
      d[v2 + 32768 / 2] = d[u] + 1;
      q.push(v2 + 32768 / 2);
    }
  }

  for (int i = 0; i < n; i++) printf("%d%c", d[a[i]], " \n"[i == n - 1]);

  return 0;
}
