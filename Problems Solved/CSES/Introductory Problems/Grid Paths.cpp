// Si puedes imaginarlo puedes programarlo
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
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]

typedef long long ll;

const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

bool vis[9][9];

string s;
int d[48];

ll solve(int k, int i, int j, int v = 1) {
  if (k == 48) return (i == 7 && j == 1 && v == 7 * 7);
  if (i == 7 && j == 1) return 0;
  if (!vis[i - 1][j] && !vis[i + 1][j] && vis[i][j + 1] && vis[i][j - 1])
    return 0;
  if (!vis[i][j + 1] && !vis[i][j - 1] && vis[i + 1][j] && vis[i - 1][j])
    return 0;

  vis[i][j] = true;

  if (d[k] < 4) {
    int r = i + dr[d[k]], c = j + dc[d[k]];
    if (!vis[r][c]) {
      ll ret = solve(k + 1, r, c, v + 1);
      vis[i][j] = false;
      return ret;
    }
    vis[i][j] = false;
    return 0;
  }
  ll ret = 0;
  fore(m, 0, 4) {
    int r = i + dr[m], c = j + dc[m];
    if (!vis[r][c]) ret += solve(k + 1, r, c, v + 1);
  }
  vis[i][j] = false;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  fore(i, 0, SZ(s)) {
    if (s[i] == 'D')
      d[i] = 0;
    else if (s[i] == 'U')
      d[i] = 1;
    else if (s[i] == 'R')
      d[i] = 2;
    else if (s[i] == 'L')
      d[i] = 3;
    else
      d[i] = 4;
  }
  fore(i, 0, 9) fore(j, 0, 9) vis[i][j] = true;
  fore(i, 1, 8) fore(j, 1, 8) vis[i][j] = false;
  cout << solve(0, 1, 1) << "\n";
  return 0;
}
