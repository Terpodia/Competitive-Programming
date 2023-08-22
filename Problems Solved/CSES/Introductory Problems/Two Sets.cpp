// Si puedes imaginarlo puedes programarlo
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
#define erof(i, x, n) for (auto i = (x); i > (n); i--)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  bool c[n];
  fore(i, 0, n) c[i] = (i % 2 == 0);
  ll s1 = 0, s2 = 0;

  if (n % 2 == 1) c[n - 1] = false;

  fore(i, 0, n)(c[i]) ? s1 += (ll)i + 1 : s2 += (ll)i + 1;

  if ((s2 - s1) % 2 == 1) {
    cout << "NO\n";
    return 0;
  }

  ll m = (s2 - s1) / 2;
  if (m % 2 == 1) c[0] = false, m++;
  fore(i, 0, n) {
    if (i + 1 == m) c[i] = true;
  }
  cout << "YES\n";
  vector<int> a1, a2;
  fore(i, 0, n)(c[i]) ? a1.pb(i + 1) : a2.pb(i + 1);
  cout << SZ(a1) << "\n";
  for (int i : a1) cout << i << " ";
  cout << "\n";
  cout << SZ(a2) << "\n";
  for (int i : a2) cout << i << " ";
  cout << "\n";
  return 0;
}
