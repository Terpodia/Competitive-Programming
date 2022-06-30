#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n...................................................\n";

typedef __uint128_t u128;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    char a[8][8];
    rep(i, 0, 8) rep(j, 0, 8) scanf(" %c", &a[i][j]);

    pair<int, int> ans = {-1, -1};

    rep(r, 1, 7) rep(c, 1, 7) {
      if (ans.f != -1) break;

      bool can = true;
      for (int i = 0; r + i < 8 && c + i < 8; i++)
        can &= (a[r + i][c + i] == '#');

      for (int i = 0; r + i < 8 && c - i > -1; i++)
        can &= (a[r + i][c - i] == '#');

      for (int i = 0; r - i > -1 && c - i > -1; i++)
        can &= (a[r - i][c - i] == '#');

      for (int i = 0; r - i > -1 && c + i < 8; i++)
        can &= (a[r - i][c + i] == '#');

      if (can) ans = {r + 1, c + 1};
    }
    printf("%d %d\n", ans.f, ans.s);
  }
  return 0;
}

