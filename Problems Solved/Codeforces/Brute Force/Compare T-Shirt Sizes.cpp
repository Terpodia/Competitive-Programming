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

int main() {
  set_IO();
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    int t1 = -1, t2 = -1;

    for (char c : a) {
      if (c == 'X')
        cnt1++;
      else if (c == 'S')
        t1 = 0;
      else if (c == 'M')
        t1 = 1;
      else
        t1 = 2;
    }
    for (char c : b) {
      if (c == 'X')
        cnt2++;
      else if (c == 'S')
        t2 = 0;
      else if (c == 'M')
        t2 = 1;
      else
        t2 = 2;
    }

    if (t1 != t2) {
      if (t1 < t2)
        cout << "<\n";
      else
        cout << ">\n";
    } else {
      if (cnt1 == cnt2)
        cout << "=\n";
      else {
        if (t1 == 0) {
          if (cnt1 > cnt2)
            cout << "<\n";
          else
            cout << ">\n";
        } else {
          if (cnt1 > cnt2)
            cout << ">\n";
          else
            cout << "<\n";
        }
      }
    }
  }

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
