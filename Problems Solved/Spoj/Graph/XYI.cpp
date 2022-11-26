#include <cstdio>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

int n, m;
vector<int> g[500];

bool isX() {
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) > 4 || sz(g[i]) == 3 || sz(g[i]) == 0) return false;

    if (sz(g[i]) == 4)
      cnt[0]++;
    else if (sz(g[i]) == 1)
      cnt[1]++;
  }
  return cnt[0] == 1 && cnt[1] == 4;
}

bool isY() {
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) >= 4 || sz(g[i]) == 0) return false;

    if (sz(g[i]) == 3)
      cnt[0]++;
    else if (sz(g[i]) == 1)
      cnt[1]++;
  }
  return cnt[0] == 1 && cnt[1] == 3;
}

bool isI() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) > 2 || sz(g[i]) == 0) return false;
    if (sz(g[i]) == 1) cnt++;
  }
  return cnt == 2;
}

void solve() {
  if (isX())
    printf("X\n");
  else if (isY())
    printf("Y\n");
  else if (isI())
    printf("I\n");
  else
    printf("NotValid\n");
}

int main() {
  int tt, _ = 1;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    printf("Case %d: ", _++);
    solve();
    for (int i = 0; i < n; i++) g[i].clear();
  }
  return 0;
}
