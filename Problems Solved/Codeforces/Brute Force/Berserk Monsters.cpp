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

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n], d[n];
    fore(i, 0, n) cin >> a[i];
    fore(i, 0, n) cin >> d[i];

    set<int> alive;
    set<int> cur;
    fore(i, 0, n) {
      alive.insert(i);
      cur.insert(i);
    }
    fore(i, 0, n) {
      set<int> dead, add, rem;
      int ans = 0;
      for (int c : cur) {
        int total = 0;
        auto it = alive.lower_bound(c);
        it++;
        if (it != alive.end()) total += a[*it];
        it--;
        if (it != alive.begin()) it--, total += a[*it];
        if (total > d[c]) {
          dead.insert(c);
          ans++;
        }
      }
      for (int c : dead) {
        auto it = alive.lower_bound(c);
        int l = -1, r = -1;
        it++;
        if (it != alive.end()) r = *it;
        it--;
        if (it != alive.begin()) it--, l = *it;
        if (l != -1 && dead.find(l) == dead.end()) add.insert(l);
        if (r != -1 && dead.find(r) == dead.end()) add.insert(r);
      }
      for (int c : cur) {
        bool can = true;
        auto it = alive.lower_bound(c);
        it++;
        if (it != alive.end()) {
          if (dead.find(*it) != dead.end()) can = false;
        }
        it--;
        if (it != alive.begin()) {
          it--;
          if (dead.find(*it) != dead.end()) can = false;
        }
        if (can) rem.insert(c);
      }
      for (int c : dead) {
        alive.erase(c);
        cur.erase(c);
      }
      for (int c : rem)
        if (cur.find(c) != cur.end()) cur.erase(c);
      for (int c : add) cur.insert(c);
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}
