#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

const int MAXN = 1e5;

int n, m, a[MAXN];
vector<int> g[MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) scanf("%d", a + i);

  queue<int> Q;
  for (int i = 0; i < n; i++)
    if (a[i] == 0) Q.push(i);

  vector<int> ans, cnt(n, 0);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (cnt[u] != a[u]) continue;
    ans.push_back(u + 1);
    cnt[u]++;
    for (int v : g[u]) {
      cnt[v]++;
      if (a[v] == cnt[v]) Q.push(v);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++)
    printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);

  return 0;
}
