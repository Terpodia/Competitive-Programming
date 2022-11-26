#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int aux;
void fastIO() { cin.tie(0)->sync_with_stdio(0); }
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

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)
#define LSOne(x) (x) & (-x)

class FenwickTree {
 private:
  int N;
  vector<ordered_set<pair<int, int>>> ft;

  int rsq(int j, int k) {
    int ret = 0;
    for (int i = j; i > 0; i -= LSOne(i)) {
      ret += (int)ft[i].size() - (int)ft[i].order_of_key({k, 0});
    }
    return ret;
  }

 public:
  FenwickTree() {}
  FenwickTree(vector<int> &a) {
    N = sz(a);
    ft = vector<ordered_set<pair<int, int>>>(N + 1);
    for (int i = 0; i < sz(a); i++) update(i + 1, a[i]);
  }
  void update(int j, int v, int old_v = -1) {
    for (int i = j; i <= N; i += LSOne(i)) {
      if (old_v != -1) ft[i].erase({old_v, j});
      ft[i].insert({v, j});
    }
  }
  int query(int l, int r, int k) { return rsq(r, k) - rsq(l - 1, k); }
};

int main() {
  int n;
  scan(n);
  vector<int> a(n);
  scan(a);
  FenwickTree ft(a);
  int q;
  scan(q);
  while (q--) {
    int t;
    scan(t);
    if (t == 0) {
      int i, j, c;
      scan(i, j, c);
      printf("%d\n", ft.query(i, j, c));
    } else {
      int i, v;
      scan(i, v);
      ft.update(i, v, a[i - 1]);
      a[i - 1] = v;
    }
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
