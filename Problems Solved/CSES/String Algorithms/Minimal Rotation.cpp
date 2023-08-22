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
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;

int min_cyclic_string(string s) {
  int n = SZ(s), l = 0, r = 1, x = 1, i = 0;
  s += s;
  while (l + n != r) {
    if (s[l + i] == s[r + i] && ++i == x)
      r += i, i = 0;
    else if (s[l + i] < s[r + i])
      r += i + 1, x = r - l, i = 0;
    else if (s[l + i] > s[r + i])
      l = r, r = l + 1, x = 1, i = 0;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int p = min_cyclic_string(s), n = SZ(s);
  s += s;
  cout << s.substr(p, n) << "\n";
  return 0;
}
