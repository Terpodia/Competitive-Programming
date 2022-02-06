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

int n, m;
string s, t, p;

void solve() {
  int cnt[27];
  memset(cnt, 0, sizeof(cnt));
  for (char c : p)
    cnt[c - 'a']++;
  
  bool can = true;
  int i = 0, j = 0;
  while (j < sz(t)) {
    if (s[i] == t[j]) i++, j++;
    else {
      if (cnt[t[j] - 'a'] <= 0) {
        can = false;
        break;
      } else {
        cnt[t[j] - 'a']--;
        j++;
      }
    }
  }
  if (i < n) can = false;
  (!can) ? cout << "NO\n" : cout << "YES\n";
}

int main() {
  set_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> s >> t >> p;
    n = sz(s), m = sz(t);
    if (m < n) cout << "NO\n";
    else {
      while (sz(s) < sz(t)) s.push_back('-');
      solve();
    }
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
