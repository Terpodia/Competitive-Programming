// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
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
#define line cout << "\n....................................\n";

const int MAXN = 2e5;
const int p[] = {-1, -1, 0, 1, 1, 0};

int n, q, a[MAXN], b[MAXN], c[MAXN], f[MAXN];

bool can() { return f[n - 1] == 0 && f[n - 2] == 0; }

void update(int i, int x) {
  i += 6 * ((n - 1 - i) / 6);
  int cnt = 0;
  rep(j, i, n) f[j] += x * p[cnt++];
}

int main() {
  scanf("%d%d", &n, &q);
  rep(i, 0, n) scanf("%d", a + i);
  rep(i, 0, n) scanf("%d", b + i);
  rep(i, 0, n) c[i] = a[i] - b[i];
  rep(i, 0, n) {
    f[i] = -c[i];
    if (i - 1 >= 0) f[i] += f[i - 1];
    if (i - 2 >= 0) f[i] -= f[i - 2];
  }
  (can()) ? puts("YES") : puts("NO");
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    l--, r--;
    int cnt = (r - l + 1) % 6;
    rep(i, r, r - cnt) update(i, x);

    (can()) ? puts("YES") : puts("NO");
  }
  return 0;
}
