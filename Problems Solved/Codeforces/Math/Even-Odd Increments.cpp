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
typedef long long ll;

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    int n, q;
    scan(n, q);
    ll a[n];
    rep(i, 0, n) scan(a[i]);
    ll se = 0, so = 0, cnte = 0, cnto = 0;
    rep(i, 0, n)(a[i] % 2 == 0) ? se += a[i] : so += a[i];
    rep(i, 0, n)(a[i] % 2 == 0) ? cnte++ : cnto++;

    while (q--) {
      int type;
      ll x;
      scan(type, x);
      if (type == 0) {
        if (x % 2 == 0)
          se += x * cnte;
        else
          so += se + x * cnte, cnto += cnte, se = 0, cnte = 0;
      } else {
        if (x % 2 == 0)
          so += x * cnto;
        else
          se += so + x * cnto, cnte += cnto, so = 0, cnto = 0;
      }
      printf("%lld\n", se + so);
    }
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
