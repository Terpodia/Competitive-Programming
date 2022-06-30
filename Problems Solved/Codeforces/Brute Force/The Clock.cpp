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

int h, m, x;

bool check[24][60];

void solve() {
  int ans = 0;
  while (!check[h][m]) {
    check[h][m] = true;
    string s;
    if (h < 10) s.push_back('0');
    s += to_string(h);
    if (m < 10) s.push_back('0');
    s += to_string(m);

    if (s[0] == s[3] && s[1] == s[2]) ans++;

    h = (h + x / 60) % 24;
    m += x % 60;

    if (m >= 60) h = (h + m / 60) % 24, m %= 60;
  }

  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d:%d%d", &h, &m, &x);
    memset(check, false, sizeof(check));
    solve();
  }
  return 0;
}

