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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int l = 0, r = n - 1; l < r; l++, r--) {
      if (s[l] != s[r]) cnt1++;
    }
    for (char c : s)
      if (c == '0') cnt2++;

    if (cnt1 == 0) {
      if (cnt2 == 1)
        cout << "BOB\n";
      else if (n % 2 == 1 && s[n / 2] == '0')
        cout << "ALICE\n";
      else
        cout << "BOB\n";
    } else {
      if (n % 2 == 1 && cnt2 == 2 && s[n / 2] == '0')
        cout << "DRAW\n";
      else
        cout << "ALICE\n";
    }
  }
  return 0;
}
