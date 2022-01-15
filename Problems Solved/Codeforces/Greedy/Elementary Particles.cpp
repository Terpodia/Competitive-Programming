#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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
void scan(T &head, U &... tail) {
  _scan(head);
  scan(tail...);
}
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    int n;
    scan(n);
    vector<int> a(n);
    scan(a);

    map<int, vector<int>> mp;
    FOR(i, 0, n) mp[a[i]].push_back(i);

    bool can = false;
    FOR(i, 0, n) if (sz(mp[a[i]]) > 1) can = true;

    if (!can)
      printf("-1\n");
    else {
      int ans = 0;
      for (auto it = mp.begin(); it != mp.end(); it++) {
        FOR(i, 1, sz(it->second)) {
          ans = max(ans, min(it->second[i], it->second[i - 1]) +
                             min(n - it->second[i], n - it->second[i - 1]));
        }
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
