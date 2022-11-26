#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 107;

int n, m, b[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<vector<int>> ans;
multiset<int> s;

void solve(int v, int r, bool flag) {
  if (v == n) return;

  if (r == -1) {
    for (int j = 0; j < m; j++) {
      vis[v][j] = true;
      auto itr = s.find(b[v][j]);
      bool f = false;

      if (itr != s.end()) {
        f = true;
        s.erase(itr);
      }

      ans[v][j] = b[v][j];
      solve(v + 1, j, f);
    }

    return;
  }

  if (flag) {
    for (int j = 0; j < m; j++) {
      if (!vis[v][j]) {
        vis[v][j] = true;
        ans[v][r] = b[v][j];
        solve(v + 1, r, flag);
        return;
      }
    }
  }

  for (int j = 0; j < m; j++) {
    auto itr = s.find(b[v][j]);
    if (!vis[v][j] && itr != s.end()) {
      vis[v][j] = true;
      ans[v][r] = b[v][j];
      s.erase(itr);

      solve(v + 1, r, true);
      return;
    }
  }

  for (int j = 0; j < m; j++) {
    if (!vis[v][j]) {
      vis[v][j] = true;
      ans[v][r] = b[v][j];
      solve(v + 1, r, flag);
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    ans.clear();
    s.clear();

    cin >> n >> m;
    ans.resize(n, vector<int>(m));

    vector<int> lo;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        lo.push_back(b[i][j]);
      }

    for (int i = 0; i < n; i++) sort(b[i], b[i] + m, greater<int>());

    sort(lo.begin(), lo.end());
    for (int i = 0; i < m; i++) s.insert(lo[i]);

    memset(vis, false, sizeof(vis));
    solve(0, -1, false);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << ans[i][j] << " ";

      cout << "\n";
    }
  }

  return 0;
}
