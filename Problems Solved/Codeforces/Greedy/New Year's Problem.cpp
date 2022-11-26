#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int aux;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

const int INF = 1e9 + 7;

int n, m;
vector<vector<int>> p;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

int solve() {
  vector<bool> used(m, false);
  int ans = INF;

  vector<pair<int, int>> friends[n];
  vector<pair<int, int>> t[m];

  FOR(i, 0, n) FOR(j, 0, m) friends[i].push_back({p[j][i], j});
  FOR(i, 0, n) sort(friends[i].begin(), friends[i].end(), cmp);
  FOR(i, 0, m) FOR(j, 0, n) t[i].push_back({p[i][j], j});
  FOR(i, 0, m) sort(t[i].begin(), t[i].end(), cmp);
  FOR(i, 0, n) used[friends[i][0].second] = true;

  int cnt = 0;
  FOR(i, 0, m) if (used[i]) cnt++;
  FOR(i, 0, n) ans = min(ans, friends[i][0].first);
  if (cnt <= n - 1) return ans;

  int hi = -INF;

  FOR(i, 0, n) FOR(j, 1, m) {
    if (used[friends[i][j].second])
      hi = max(hi, friends[i][j].first);
    else {
      if (t[friends[i][j].second][0].second != i)
        hi = max(hi, friends[i][j].first);
      else
        hi = max(hi, t[friends[i][j].second][1].first);
    }
  }

  return min(ans, hi);
}

int main() {
  int tc;
  aux = scanf("%d", &tc);
  while (tc--) {
    aux = scanf("%d%d", &m, &n);
    p = vector<vector<int>>(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        aux = scanf("%d", &p[i][j]);
      }
    }

    printf("%d\n", solve());

    p.clear();
  }

  return 0;
}
