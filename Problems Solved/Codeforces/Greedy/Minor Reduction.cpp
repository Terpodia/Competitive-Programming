#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int aux;
void _scan(int &x) { aux = scanf("%d", &x); }
void _scan(long long &x) { aux = scanf("%lld", &x); }
void _scan(double &x) { aux = scanf("%lf", &x); }
void _scan(long double &x) { aux = scanf("%Lf", &x); }
void _scan(char &x) { aux = scanf(" %c", &x); }
void _scan(char *x) { aux = scanf("%s", x); }
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
void set_IO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  set_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    string x;
    cin >> x;
    pair<pair<int, int>, int> p[2];
    p[0] = {{-1, -1}, -1}, p[1] = {{-1, -1}, -1};
    for (int i = 0; i < sz(x) - 1; i++) {
      int d1 = x[i] - '0';
      int d2 = x[i + 1] - '0';
      if (d1 + d2 < 10) {
        p[0] = {{i, i + 1}, d1 + d2};
        break;
      }
    }
    for (int i = sz(x) - 1; i > 0; i--) {
      int d1 = x[i - 1] - '0';
      int d2 = x[i] - '0';
      if (d1 + d2 > 9) {
        p[1] = {{i - 1, i}, d1 + d2};
        break;
      }
    }
    for (int i = 0; i < sz(x); i++) {
      if (p[1].first.first != -1) {
        if (p[1].first.first == i)
          cout << p[1].second;
        else if (p[1].first.second == i)
          continue;
        else
          cout << x[i];
      } else {
        if (p[0].first.first == i)
          cout << p[0].second;
        else if (p[0].first.second == i)
          continue;
        else
          cout << x[i];
      }
    }
    cout << "\n";
  }

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
