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

const int INF = 2e9 + 1;

int n, m;
vector<int> a, b;

void calc(int d, int& p1, int& p2) {
  auto it1 = lower_bound(all(a), d);
  auto it2 = lower_bound(all(b), d);
  int r1 = (int)distance(a.begin(), it1);
  int r2 = (int)distance(b.begin(), it2);

  p1 = r1 * 2 + (n - r1) * 3;
  p2 = r2 * 2 + (m - r2) * 3;
}

int main() {
  scanf("%d", &n);
  a = vector<int>(n);
  rep(i, 0, n) scanf("%d", &a[i]);

  scanf("%d", &m);
  b = vector<int>(m);
  rep(i, 0, m) scanf("%d", &b[i]);

  sort(all(a));
  sort(all(b));

  int diff = 0, ansA = 0, ansB = 0;
  calc(INF, ansA, ansB);
  diff = ansA - ansB;

  rep(i, n - 1, -1) {
    int d = a[i];
    int p1, p2;
    calc(d, p1, p2);
    if (p1 - p2 > diff) diff = p1 - p2, ansA = p1, ansB = p2;
    if (p1 - p2 == diff && ansA < p1) ansA = p1, ansB = p2;
  }

  printf("%d:%d\n", ansA, ansB);

  return 0;
}
