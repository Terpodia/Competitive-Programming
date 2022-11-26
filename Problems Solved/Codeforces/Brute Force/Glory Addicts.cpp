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

ll solve(int curr, vector<ll> &fire, vector<ll> &frost) {
  int i = 0, j = 0;
  int n = sz(fire) - (curr == 0), m = sz(frost) - (curr == 1);
  ll ret = 0;

  if (curr == 0)
    ret += fire.back();
  else
    ret += frost.back();

  curr = 1 - curr;

  while (i < n || j < m) {
    if (i >= n) {
      ret += 2 * frost[j];
      for (j++; j < m; j++) ret += frost[j];
      break;
    }
    if (j >= m) {
      ret += 2 * fire[i];
      for (i++; i < n; i++) ret += fire[i];
      break;
    }
    if (curr == 0)
      ret += 2 * fire[i++];
    else
      ret += 2 * frost[j++];
    curr = 1 - curr;
  }

  return ret;
}

int main() {
  int tt;
  scan(tt);
  while (tt--) {
    int n;
    scan(n);
    ll a[n], b[n];
    rep(i, 0, n) scan(a[i]);
    rep(i, 0, n) scan(b[i]);

    vector<ll> fire, frost;
    rep(i, 0, n) {
      if (a[i] == 0)
        fire.pb(b[i]);
      else
        frost.pb(b[i]);
    }
    if (!fire.empty()) sort(all(fire), greater<ll>());
    if (!frost.empty()) sort(all(frost), greater<ll>());

    if (fire.empty()) {
      ll s = 0;
      rep(i, 0, sz(frost)) s += frost[i];
      printf("%lld\n", s);
    } else if (frost.empty()) {
      ll s = 0;
      rep(i, 0, sz(fire)) s += fire[i];
      printf("%lld\n", s);
    } else {
      printf("%lld\n", max(solve(0, fire, frost), solve(1, fire, frost)));
    }
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
