#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

struct S {
  int l, r;
  bool flag;
};

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  vector<bool> f(n, false);
  S p[n];
  fore(i, 0, n) cin >> a[i];
  fore(i, 0, n) {
    p[i].l = p[i].r = -1;
    p[i].flag = false;
  }

  int sz = 0;

  fore(i, 0, n) {
    if (a[i] == 0) {
      sz++;
      continue;
    }
    if (p[sz].l == -1) p[sz].l = i;
    p[sz].r = i;
    if (a[i] == 2) p[sz].flag = true;
  }
  int ans = 0;
  fore(i, 0, n) {
    if (p[i].l == -1) continue;
    ans++;
    if (p[i].flag) {
      if (p[i].l != 0) f[p[i].l - 1] = true;
      if (p[i].r != n - 1) f[p[i].r + 1] = true;
      continue;
    }
    if (p[i].l != 0 && !f[p[i].l - 1])
      f[p[i].l - 1] = true;
    else if (p[i].l != n - 1 && !f[p[i].r + 1])
      f[p[i].r + 1] = true;
  }
  fore(i, 0, n) if (a[i] == 0) ans += !f[i];
  cout << ans << "\n";

  return 0;
}
