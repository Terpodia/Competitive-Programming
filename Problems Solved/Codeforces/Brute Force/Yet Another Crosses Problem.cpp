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
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... U>
void _dbg(istream_iterator<string> it, T &head, U &...tail) {
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

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    int n, m;
    scan(n, m);
    char a[n][m];
    rep(i, 0, n) rep(j, 0, m) scan(a[i][j]);
    int cnt[m];
    memset(cnt, 0, sizeof(cnt));
    rep(i, 0, m) rep(j, 0, n) if (a[j][i] == '*') cnt[i]++;
    int ans = INF;
    rep(i, 0, n) {
      int s1 = 0, s2 = 0;
      rep(j, 0, m) {
        if (a[i][j] == '*')
          s1++, s2 = max(s2, cnt[j]);
        else
          s2 = max(s2, cnt[j] + 1);
      }
      ans = min(ans, n - s1 + m - s2);
    }
    printf("%d\n", ans);
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
