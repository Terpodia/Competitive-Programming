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
typedef long double ld;

const int MAXN = 1e5;
const ld INF = 1e18;

int n;
ld x[MAXN], t[MAXN];

bool can(ld k) {
  pair<ld, ld> s[n];
  rep(i, 0, n) s[i].fst = x[i] - k + t[i], s[i].snd = x[i] + k - t[i];

  ld l = s[0].fst, r = s[0].snd;

  rep(i, 1, n) {
    if (s[i].fst > r || s[i].snd < l) return false;
    l = max(l, s[i].fst);
    r = min(r, s[i].snd);
  }
  return true;
}
ld pos(ld k) {
  pair<ld, ld> s[n];
  rep(i, 0, n) s[i].fst = x[i] - k + t[i], s[i].snd = x[i] + k - t[i];

  ld l = s[0].fst, r = s[0].snd;

  rep(i, 1, n) {
    if (s[i].fst > r || s[i].snd < l) return false;
    l = max(l, s[i].fst);
    r = min(r, s[i].snd);
  }
  return r;
}

ld bs() {
  ld l = *max_element(t, t + n), r = INF;
  rep(i, 0, 100) {
    ld mid = (l + r) / 2;
    if (can(mid))
      r = mid;
    else
      l = mid;
  }
  return r;
}

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    scan(n);
    rep(i, 0, n) scan(x[i]);
    rep(i, 0, n) scan(t[i]);
    printf("%.7Lf\n", pos(bs()));
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
