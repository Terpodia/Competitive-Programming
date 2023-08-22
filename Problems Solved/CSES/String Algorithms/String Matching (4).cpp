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

vector<int> kmppre(string& s) {
  vector<int> b(SZ(s) + 1, -1);
  int j = -1;
  fore(i, 0, SZ(s)) {
    while (j > -1 && s[i] != s[j]) j = b[j];
    b[i + 1] = ++j;
  }
  return b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string t, p;
  cin >> t >> p;
  string s = p;
  s += "$";
  s += t;
  vector<int> b = kmppre(s);
  int ans = 0;
  fore(i, SZ(p) + 2, SZ(b)) if (b[i] == SZ(p)) ans++;
  cout << ans << "\n";
  return 0;
}
