#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

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

void fast_IO() { cin.tie(0)->sync_with_stdio(0); }

typedef __uint128_t u128;
typedef pair<int, int> ii;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5, x[] = {2, 5};

int n, e[MAXN];
vector<ii> g[MAXN];
bool can;

void dfs(int u, int f=0, int p=-1) {
  if (sz(g[u]) > 2) can = false;
  for (auto& [v, i] : g[u]) if (v != p) {
    e[i] = x[f]; 
    f = !f;
    dfs(v, f, u);
  }
}

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    scan(n);
    FOR(i, 0, n - 1) {
      int u, v;
      scan(u, v);
      u--, v--;
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }
    can = true;
    dfs(0);
    if (!can)
      printf("-1\n");
    else
      FOR(i, 0, n - 1) printf("%d%c", e[i], " \n"[i == n - 2]);

    FOR(i, 0, n) g[i].clear();
  }
  return 0;
}

