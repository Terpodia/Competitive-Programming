//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct color {
  int l, r, pref_sum;
  color() {}
  color(int _l, int _r, int _s) : l(_l), r(_r), pref_sum(_s) {}
};

const int MAXN = 2e5;

int n, m, k, a[MAXN];
vector<vector<color>> b;

vector<vector<color>> calc() {
  vector<vector<color>> ret(m + 1);
  rep(i, 0, m + 1) ret[i].pb(color(-1, -1, 0));

  int j = 0;
  while (j < n) {
    int l = j, r = j;
    while (r + 1 < n && a[l] == a[r + 1]) r++;
    ret[a[l]].pb(color(l, r, r - l + 1));
    j = r + 1;
  }
  rep(i, 1, m + 1) {
    rep(z, 1, sz(ret[i])) ret[i][z].pref_sum += ret[i][z - 1].pref_sum;
  }
  return ret;
}

int solve(int i, int j) {
  int l = j, r = sz(b[i]) - 1;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    int d = (b[i][mid].r - b[i][j].l + 1) -
            (b[i][mid].pref_sum - b[i][j - 1].pref_sum);
    if (d <= k)
      l = mid;
    else
      r = mid - 1;
  }
  return b[i][l].pref_sum - b[i][j - 1].pref_sum;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  rep(i, 0, n) scanf("%d", a + i);
  b = calc();

  int ans = 1;

  rep(i, 1, m + 1) rep(j, 1, sz(b[i])) { ans = max(ans, solve(i, j)); }

  printf("%d\n", ans);

  return 0;
}

