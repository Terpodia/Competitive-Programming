#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4;
int p[MAXN];
char c[MAXN];
vector<int> g[MAXN];

pair<int, int> dfs(int v, int& cnt) {
  pair<int, int> ret = {0, 0};
  (c[v] == 'W') ? ret.first++ : ret.second++;
  for (int u : g[v])
    if (u != p[v]) {
      pair<int, int> res;
      res = dfs(u, cnt);
      ret.first += res.first, ret.second += res.second;
    }
  if (ret.first == ret.second) cnt++;
  return ret;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    p[0] = -1;
    for (int i = 1; i < n; i++) {
      int v;
      scanf("%d", &v);
      p[i] = v - 1;
      g[i].push_back(p[i]);
      g[p[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) scanf(" %c", &c[i]);
    int cnt = 0;
    dfs(0, cnt);
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) g[i].clear();
  }
  return 0;
}
