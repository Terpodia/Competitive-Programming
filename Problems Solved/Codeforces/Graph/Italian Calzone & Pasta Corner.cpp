#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int n, m, a[101][101];

const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int solve(int r, int c) {
  int ans = a[r][c] - 1, ls = a[r][c];
  bool vis[n][m];
  memset(vis, false, sizeof(vis));
  priority_queue<pair<int, ii>> pq;

  pq.push(mp(-a[r][c], mp(r, c)));
  vis[r][c] = true;

  while (!pq.empty()) {
    auto [val, pos] = pq.top();
    pq.pop();
    val *= -1;
    ans += val - ls - 1, ls = val;
    fore(_, 0, 4) {
      int i = dr[_] + pos.fst, j = dc[_] + pos.snd;
      if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || ls > a[i][j])
        continue;
      vis[i][j] = true;
      pq.push(mp(-a[i][j], mp(i, j)));
    }
  }
  ans++;
  ans += n * m - ls;
  ans = n * m - ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fore(i, 0, n) fore(j, 0, m) cin >> a[i][j];
  int ans = 0;
  fore(i, 0, n) fore(j, 0, m) { ans = max(ans, solve(i, j)); }
  cout << ans << "\n";
  return 0;
}
