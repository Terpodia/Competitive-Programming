#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(long double &x) { scanf("%Lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
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
void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... U>
void _dbg(istream_iterator<string> it, T &head, U &... tail) {
  cout << *it << "=" << head << " ";
  _dbg(++it, tail...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n-----------------------------\n";
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

typedef __uint128_t u128;

const int INF = 1e9;

string s;
int a[10][10][10][10];

int main() {
  set_IO();
  cin >> s;

  rep(i, 0, 10) rep(j, 0, 10) rep(k, 0, 10) rep(w, 0, 10) a[i][j][k][w] = INF;

  rep(i, 0, 10) rep(j, 0, 10) {
    rep(x, 0, 10) rep(y, 0, 10) {
      if (x == 0 && y == 0) continue;
      rep(d, 0, 10) {
        int v = (d + i * x + j * y) % 10;
        a[i][j][d][v] = min(a[i][j][d][v], x + y - 1);
      }
    }
  }

  int ans[10][10];
  memset(ans, -1, sizeof(ans));

  rep(i, 0, 10) rep(j, i, 10) {
    int curr = 0, v = 0;
    bool can = true;
    rep(k, 1, sz(s)) {
      if (a[i][j][curr][s[k] - '0'] == INF) {
        can = false;
        break;
      }
      v += a[i][j][curr][s[k] - '0'];
      curr = s[k] - '0';
    }
    if (!can) continue;
    ans[i][j] = ans[j][i] = v;
  }

  rep(i, 0, 10) rep(j, 0, 10) cout << ans[i][j] << " \n"[j == 9];

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
