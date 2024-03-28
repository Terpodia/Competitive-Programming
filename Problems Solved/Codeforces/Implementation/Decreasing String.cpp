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
ll p;

void solve() {
  int cnt = SZ(s), i = 0;
  int a[cnt];
  fore(j, 0, cnt) a[j] = j;

  while (p >= cnt && i < SZ(s)) {
    int j = i;
    while (j < SZ(s) && s[i] == s[j]) j++;
    if (j == SZ(s)) {
      cout << s[i];
      return;
    }

    while (j < SZ(s) && s[j - 1] <= s[j]) j++;

    int l = j - 1, r = j;

    while (l >= i) {
      if (p < cnt) break;

      if (s[l] == '-')
        l = a[l];

      else if (r >= SZ(s) || s[l] > s[r]) {
        s[l] = '-';
        if (l > i) a[l] = a[l - 1];
        l--;
        p -= cnt, cnt--;
      }

      else if (s[l] <= s[r])
        l = r++;
    }
    i = r;
  }
  for (char c : s) {
    if (c == '-') continue;
    if (p == 0) {
      cout << c;
      return;
    }
    p--;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s >> p;
    p--;
    solve();
  }
  cout << "\n";
  return 0;
}
