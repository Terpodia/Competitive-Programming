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

const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int n, m;
string t, a[1000], maze[1000];

void build() {
  fore(i, 0, n) maze[i].clear();
  string q = t;
  q += t;
  fore(i, 0, n) {
    fore(j, 0, m) {
      string r = q.substr(j, m);
      bool flag = true;
      fore(k, 0, m) {
        flag &= ((r[k] == '1' && a[i][k] == '0') || r[k] == '0');
      }
      flag ? maze[i] += "0" : maze[i] += "1";
    }
  }
}

bool can = false;

void solve() {
  queue<pair<int, int>> q;
  bool vis[n][m];
  memset(vis, false, sizeof(vis));
  fore(i, 0, m) if (maze[0][i] == '0') q.push(mp(0, i)), vis[0][i] = true;

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (i == n - 1) {
      can = true;
      return;
    }
    for (int _ = 0; _ < 4; _++) {
      int r = dr[_] + i, c = dc[_] + j;
      c = (((c + m) % m) + m) % m;
      if (r < 0 || r >= n || vis[r][c] || maze[r][c] == '1') continue;
      vis[r][c] = true;
      q.push(mp(r, c));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> t;
  fore(i, 0, n) cin >> a[i];
  build();

  solve();

  reverse(all(t));
  build();
  solve();

  if (can)
    cout << "Y\n";
  else
    cout << "N\n";

  return 0;
}
