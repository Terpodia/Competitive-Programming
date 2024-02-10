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

bool valid(string& s) {
  int cnt = 0;
  for (char c : s) {
    if (c == '(')
      cnt++;
    else
      cnt--;
    if (cnt < 0) return false;
  }
  return cnt == 0;
}

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
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (char c : s) (c == '(') ? cnt0++ : cnt1++;

    if (cnt0 != cnt1)
      cout << "-1\n";
    else {
      string t = s;
      reverse(all(t));
      if (valid(s) || valid(t)) {
        cout << "1\n";
        fore(i, 0, n) cout << "1 ";
        cout << "\n";
        continue;
      }
      vector<int> c(n, 2);

      int x = 0;

      fore(i, 0, n) {
        if (s[i] == ')')
          cnt1--;
        else
          x++;
        if (x == cnt1) break;
      }

      int y = x;

      fore(i, 0, n) {
        if (s[i] == '(') c[i] = 1, x--;
        if (x == 0) break;
      }
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') c[i] = 1, y--;
        if (y == 0) break;
      }

      cout << "2\n";
      for (int i : c) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}
