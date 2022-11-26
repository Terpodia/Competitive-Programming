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
#define all(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
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

const int MAXN = 1e6;

int m, n;
int p[MAXN];

int ans;
bool can = true;

void dfs(int u, int h = 0) {
  if (h == n) return;

  int k = 1 << (n - h);

  dfs(u, h + 1);
  dfs(u + k / 2, h + 1);

  bool check = false;
  if (p[u] > p[u + k / 2]) check = true;

  if (check) {
    ans++;
    rep(i, u, u + k / 2) swap(p[i], p[i + k / 2]);
  }
  rep(i, u, u + k - 1) can &= p[i] < p[i + 1];
}

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    scan(m);
    rep(i, 0, m) scan(p[i]);
    n = (int)log2(m);

    can = true, ans = 0;
    dfs(0, 0);

    if (!can)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
