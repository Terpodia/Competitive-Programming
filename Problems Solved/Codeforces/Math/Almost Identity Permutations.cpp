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

typedef long long ll;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  ll subfactorial[k + 1], comb[n + 1][n + 1];

  rep(i, 0, n + 1) rep(j, 0, k + 1) comb[i][j] = 0;

  rep(i, 0, n + 1) comb[i][0] = 1;
  rep(i, 0, n + 1) comb[i][i] = 1;

  rep(i, 1, n + 1) rep(j, 1, k + 1) {
    if (j >= i) break;
    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
  }

  subfactorial[0] = 1, subfactorial[1] = 0;
  rep(i, 2, k + 1) {
    subfactorial[i] = (ll)(i - 1) * (subfactorial[i - 1] + subfactorial[i - 2]);
  }

  ll ans = 0;
  rep(i, 0, k + 1) { ans += comb[n][i] * subfactorial[i]; }
  printf("%lld\n", ans);

  return 0;
}

