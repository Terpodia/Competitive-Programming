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
  int n;
  string s;
  cin >> n >> s;
  int m = n;
  vector<int> p;
  fore(i, 0, n) if (s[i] == '8') p.pb(i);
  int i = 0, j = 0, cur = 0;
  while (m > 11) {
    if (j == SZ(p)) {
      cout << "NO\n";
      return 0;
    }
    if (cur == 0) {
      while (i < n && (s[i] == '8' || s[i] == '-')) i++;
      if (i == n)
        s[p[j++]] = '-';
      else
        s[i] = '-';
      m--;
    } else {
      s[p[j++]] = '-';
      m--;
    }
    cur = 1 - cur;
  }
  fore(k, 0, n) if (s[k] != '-') {
    if (s[k] == '8')
      cout << "YES\n";
    else
      cout << "NO\n";
    return 0;
  }
  return 0;
}
