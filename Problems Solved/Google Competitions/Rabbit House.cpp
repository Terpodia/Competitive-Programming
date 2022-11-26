#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

/*
struct box{
    ll val;
    int x, y;

    bool operator<(const box& a) const { return val < a.val; }
    bool operator>(const box& a) const { return val > a.val; }
};
*/

const int MAXN = 300, xd[] = {1, -1, 0, 0}, yd[] = {0, 0, 1, -1};
int R, C;
ll a[MAXN][MAXN];
priority_queue<pair<ll, pair<int, int>>> pq;

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

ll solve() {
  ll ans = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) pq.push({a[i][j], {i, j}});

  while (!pq.empty()) {
    pair<ll, pair<int, int>> b = pq.top();
    pq.pop();
    for (int i = 0; i < 4; i++) {
      int x2 = b.second.first + xd[i], y2 = b.second.second + yd[i];
      if (x2 >= R || x2 < 0 || y2 >= C || y2 < 0 || b.first - a[x2][y2] <= 1)
        continue;

      ans += b.first - a[x2][y2] - 1;
      a[x2][y2] = b.first - 1;
      pq.push({a[x2][y2], {x2, y2}});
    }
  }

  return ans;
}

int main() {
  fastIO();
  int t, x = 1;
  cin >> t;
  while (t--) {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++) cin >> a[i][j];

    ll y = solve();
    cout << "Case #" << x << ": " << y << "\n";
    x++;
  }

  return 0;
}
