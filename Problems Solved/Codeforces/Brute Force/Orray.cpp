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

const int MAXN = 2e5 + 20;

int n, a[MAXN];

void solve() {
  vector<int> ans;
  int curr = a[0];
  ans.pb(a[0]);
  a[0] = -1;

  while (sz(ans) < n) {
    vector<int> pos;

    rep(i, 29, -1) {
      if (curr & (1 << i)) continue;

      if (pos.empty()) {
        rep(j, 0, n) if (a[j] != -1) {
          if (a[j] & (1 << i)) pos.pb(j);
        }
      } else {
        vector<int> aux;
        for (auto j : pos)
          if (a[j] != -1) {
            if (a[j] & (1 << i)) aux.pb(j);
          }
        if (!aux.empty()) pos = aux;
      }
    }

    if (!pos.empty()) {
      ans.pb(a[pos[0]]), curr |= a[pos[0]], a[pos[0]] = -1;
    } else {
      rep(i, 0, n) if (a[i] != -1) ans.pb(a[i]);
    }
  }

  rep(i, 0, n) printf("%d%c", ans[i], " \n"[i == n - 1]);
}

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    scan(n);
    rep(i, 0, n) scan(a[i]);
    sort(a, a + n, greater<int>());
    solve();
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
