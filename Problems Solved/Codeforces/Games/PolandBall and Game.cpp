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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<string> s[2];
  fore(i, 0, n) {
    string k;
    cin >> k;
    s[0].insert(k);
  }
  fore(i, 0, m) {
    string k;
    cin >> k;
    s[1].insert(k);
  }
  vector<string> v;
  for (auto k : s[0])
    if (s[1].find(k) != s[1].end()) v.pb(k);
  int cur = 0;
  fore(i, 0, SZ(v)) {
    s[0].erase(v[i]);
    s[1].erase(v[i]);
    cur = 1 - cur;
  }
  if (SZ(s[0]) == SZ(s[1])) {
    if (cur == 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  } else if (SZ(s[0]) > SZ(s[1]))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
