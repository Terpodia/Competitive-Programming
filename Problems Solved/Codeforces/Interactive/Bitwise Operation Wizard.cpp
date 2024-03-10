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

char query(int a, int b, int c, int d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  char ret;
  cin >> ret;
  return ret;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int k = 0;
    fore(i, 1, n) {
      char c = query(k, k, i, i);
      if (c == '<') k = i;
    }
    vector<int> idx;
    idx.pb(0);
    int cur = 0;
    fore(i, 1, n) {
      char c = query(k, cur, k, i);
      if (c == '=')
        idx.pb(i);
      else if (c == '<') {
        idx.clear();
        idx.pb(i);
        cur = i;
      }
    }
    int j = idx[0];
    for (int i : idx) {
      char c = query(j, j, i, i);
      if (c == '>') j = i;
    }
    cout << "! " << k << " " << j << endl;
  }
  return 0;
}
