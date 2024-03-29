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

string s;

bool solve(int k) {
  int cur = 0, n = SZ(s);
  fore(i, 0, k) {
    if (s[i] == '?' || s[i + k] == '?') continue;
    if (s[i] != s[i + k]) cur++;
  }
  if (cur == 0) return true;
  fore(i, k, n - k) {
    if (s[i - k] != '?' && s[i] != '?' && s[i - k] != s[i]) cur--;
    if (s[i] != '?' && s[i + k] != '?' && s[i] != s[i + k]) cur++;
    if (cur == 0) return true;
  }
  return false;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    int ans = 0;
    fore(i, 1, SZ(s)) {
      if (i * 2 > SZ(s)) break;
      if (solve(i)) ans = i * 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
