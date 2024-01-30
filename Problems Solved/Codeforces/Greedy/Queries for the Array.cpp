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
    string s;
    cin >> s;
    bool can = true;
    int sz = 0, cnt = 0, cnt2 = 0;
    fore(i, 0, SZ(s)) {
      if (sz < 2 && s[i] == '0') can = false;
      if (s[i] == '-') {
        sz--;
        cnt = max(0, cnt - 1);
        cnt2 = max(0, cnt2 - 1);
      } else if (s[i] == '+') {
        sz++;
        if (cnt > 0) cnt++;
        cnt2++;
      } else if (s[i] == '1') {
        if (cnt > 0) can = false;
        cnt2 = 0;
      } else {
        if (cnt2 == 0) can = false;
        cnt = max(1, cnt);
      }
    }
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
