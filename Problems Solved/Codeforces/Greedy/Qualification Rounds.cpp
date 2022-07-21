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

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n][k];
  rep(i, 0, n) { rep(j, 0, k) scanf("%d", &a[i][j]); }

  set<int> s;
  rep(i, 0, n) {
    int msk = 0;
    rep(j, 0, k) {
      if (a[i][j] == 1) msk |= 1 << j;
    }
    s.insert(msk);
  }

  bool can = false;

  rep(i, 0, n) {
    int msk = 0;
    rep(j, 0, k) {
      if (a[i][j] == 1) msk |= 1 << j;
    }

    rep(j, 0, 1 << k) {
      int val = j;
      rep(z, 0, k) {
        if (msk & (1 << z)) {
          val &= ~(1 << z);
        }
      }

      if (s.find(val) != s.end()) can = true;
    }
  }

  if (!can)
    puts("NO");
  else
    puts("YES");

  return 0;
}

