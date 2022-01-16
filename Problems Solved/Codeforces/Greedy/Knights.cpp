#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int aux;
void _scan(int &x) { aux = scanf("%d", &x); }
void _scan(long long &x) { aux = scanf("%lld", &x); }
void _scan(double &x) { aux = scanf("%lf", &x); }
void _scan(long double &x) { aux = scanf("%Lf", &x); }
void _scan(char &x) { aux = scanf(" %c", &x); }
void _scan(char *x) { aux = scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &... tail) {
  _scan(head);
  scan(tail...);
}
void set_IO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mr[] = {2, 2, -2, -2, 1, 1, -1, -1},
          mc[] = {1, -1, 1, -1, 2, -2, 2, -2};

int n;
char ans[100][100];
int hi = -1;

void solve(int sr, int sc) {
  char vis[n][n];
  int cnt = 0;
  FOR(i, 0, n) FOR(j, 0, n) vis[i][j] = '-';

  queue<pair<int, int>> q;
  q.push({sr, sc});
  vis[sr][sc] = 'W';

  while (!q.empty()) {
    auto [ur, uc] = q.front();
    q.pop();
    FOR(i, 0, 8) {
      int vr = ur + mr[i], vc = uc + mc[i];
      if (vr > -1 && vc > -1 && vr < n && vc < n && vis[vr][vc] == '-') {
        vis[vr][vc] = (vis[ur][uc] == 'W') ? 'B' : 'W';
        q.push({vr, vc});
        cnt++;
      }
    }
  }

  if (cnt > hi) {
    FOR(i, 0, n) FOR(j, 0, n) if (vis[i][j] == '-') vis[i][j] = 'W';
    hi = cnt;
    FOR(i, 0, n) FOR(j, 0, n) ans[i][j] = vis[i][j];
  }
}

int main() {
  set_IO();
  cin >> n;
  // FOR(i, 0, n) FOR(j, 0, n) { solve(i, j); }
  solve(0, 0);
  FOR(i, 0, n) {
    FOR(j, 0, n) cout << ans[i][j];
    cout << "\n";
  }

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
