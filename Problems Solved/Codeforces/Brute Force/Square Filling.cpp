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

const int rd[] = {1, 1, -1, -1}, cd[] = {1, -1, 1, -1}, x[] = {0, 0, -1, -1},
          y[] = {0, -1, 0, -1};
int n, m;
int a[50][50];
bool ck[50][50];
vector<pair<int, int>> op;

bool solve(int i, int j) {
  if (ck[i][j]) return true;

  pair<int, int> p;
  bool can = false;
  FOR(_, 0, 4) {
    if (can) break;
    int ni = i + rd[_], nj = j + cd[_];
    if (ni > -1 && nj > -1 && ni < n && nj < m) {
      if (a[i + x[_]][j + y[_]] == 1 && a[i + x[_] + 1][j + y[_]] == 1 &&
          a[i + x[_]][j + y[_] + 1] == 1 &&
          a[i + x[_] + 1][j + y[_] + 1] == 1) {
        can = true;
        p = {i + x[_], j + y[_]};
      }
    }
  }
  if (!can) return can;
  op.push_back({p.first, p.second});
  ck[p.first][p.second] = ck[p.first + 1][p.second] =
      ck[p.first][p.second + 1] = ck[p.first + 1][p.second + 1] = true;
  return can;
}

int main() {
  scan(n, m);
  FOR(i, 0, n) FOR(j, 0, m) scan(a[i][j]);
  bool can = true;
  FOR(i, 0, n) FOR(j, 0, m) {
    if (a[i][j] == 1) can &= solve(i, j);
    if (!can) break;
  }
  if (!can)
    puts("-1");
  else {
    printf("%d\n", sz(op));
    for (auto &[i, j] : op) printf("%d %d\n", i + 1, j + 1);
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
