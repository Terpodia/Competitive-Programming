// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define make_pair mp
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n========================================\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  pair<int, int> a[n];
  rep(i, 0, n) cin >> a[i].fst >> a[i].snd;
  sort(a, a + n);
  ld ans = 0;
  int j = n - 1;
  rep(i, n - 2, -1) {
    if (a[i].snd <= a[j].snd) {
      j = i;
      continue;
    }
    ans = max(ans, (ld)(a[j].fst - a[i].fst) / (ld)(a[i].snd - a[j].snd));
  }
  cout << ans << "\n";
  return 0;
}
