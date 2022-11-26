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

const int INF = 1e9;

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    int n;
    scan(n);
    int a[n];
    rep(i, 0, n) scan(a[i]);
    int acc = a[0];
    rep(i, 1, n) acc = __gcd(a[i], acc);

    if (acc == 1)
      puts("0");
    else {
      int pref[n + 1], suff[n + 1];
      pref[0] = 0, suff[n] = 0;
      rep(i, 1, n + 1) pref[i] = __gcd(pref[i - 1], a[i - 1]);
      rep(i, n - 1, -1) suff[i] = __gcd(suff[i + 1], a[i]);

      int ans = INF;
      rep(i, n - 1, -1) {
        if (__gcd(__gcd(a[i], i + 1), __gcd(pref[i], suff[i + 1])) == 1) {
          ans = n - (i + 1) + 1;
          break;
        }
      }
      rep(i, 0, n) {
        rep(j, n - 1, -1) {
          if (__gcd(i + 1, j + 1) == 1)
            ans = min(ans, n - (i + 1) + 1 + n - (j + 1) + 1);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
