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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5, INF = 1e9;

int n;
vector<int> a, pref;

void process() {
  sort(all(a));
  int j = 0;
  vector<int> b;
  while (j < n) {
    int cnt = 1;
    while (j + 1 < n && a[j + 1] == a[j]) cnt++, j++;
    b.push_back(cnt);
    j++;
  }
  a = b;
  pref = vector<int>(sz(a) + 1, 0);
  FOR(i, 1, sz(a) + 1) pref[i] = pref[i - 1] + a[i - 1];
}

int bs(int L, int R, int K) {
  int l = L - 1, r = R;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (pref[mid] - pref[L - 1] <= K)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

void solve() {
  process();
  int ans = INF;
  FOR(i, 0, 20) FOR(j, 0, 20) {
    int acc = 0;
    int z = bs(1, sz(a), 1 << i);
    acc += (1 << i) - pref[z];
    if (z == sz(a))
      acc += (1 << j) + 1;
    else {
      int k = bs(z + 1, sz(a), 1 << j);
      acc += (1 << j) - (pref[k] - pref[z]);
      int r = pref[sz(a)] - pref[k];
      if (__builtin_popcount(r) == 0)
        acc++;
      else if (__builtin_popcount(r) != 1)
        acc += (1 << ((int)log2(r) + 1)) - r;
    }
    ans = min(ans, acc);
  }
  printf("%d\n", ans);
}

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    scan(n);
    a = vector<int>(n);
    scan(a);
    solve();
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
