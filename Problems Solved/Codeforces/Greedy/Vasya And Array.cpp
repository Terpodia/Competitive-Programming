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
#define f first
#define s second

typedef __uint128_t u128;
typedef pair<int, int> ii;

int n, m;
vector<ii> v[2];

void solve() {
  int a[n];
  rep(i, 0, n) a[i] = n - i;
  for (auto &[l, r] : v[1]) {
    if (l < 0 || r < 0) continue;
    sort(a + l, a + r + 1);
  }
  puts("YES");
  rep(i, 0, n) printf("%d%c", a[i], " \n"[i == n - 1]);
}

void process() {
  sort(v[1].begin(), v[1].end());
  int k = 0;
  ii curr = {-1, -1};
  vector<ii> add;
  while (k < sz(v[1])) {
    if (curr.s < v[1][k].f) {
      add.push_back(curr);
      curr = v[1][k];
    }
    curr.s = max(curr.s, v[1][k].s);
    v[1][k] = {-1, -1};
    k++;
  }
  add.push_back(curr);
  rep(i, 0, sz(add)) v[1].push_back(add[i]);
}

bool check() {
  rep(i, 0, sz(v[1])) {
    if (v[1][i].f < 0 || v[1][i].s < 0) continue;
    rep(j, 0, sz(v[0])) {
      if (v[0][j].f >= v[1][i].f && v[0][j].s <= v[1][i].s) return false;
    }
  }
  return true;
}

int main() {
  scan(n, m);
  rep(i, 0, m) {
    int t;
    scan(t);
    int l, r;
    scan(l, r);
    v[t].push_back({l - 1, r - 1});
  }

  process();

  if (!check())
    puts("NO");
  else
    solve();

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
