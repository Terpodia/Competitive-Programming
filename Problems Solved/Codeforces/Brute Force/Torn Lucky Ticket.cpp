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
  int n;
  cin >> n;
  string s[n];
  fore(i, 0, n) cin >> s[i];
  ll cnt[6][50];
  memset(cnt, 0, sizeof(cnt));
  fore(i, 0, n) {
    int sum = 0;
    for (char c : s[i]) sum += (int)(c - '0');
    cnt[SZ(s[i])][sum]++;
  }
  ll ans = 0;
  fore(i, 0, n) {
    fore(sz, 1, SZ(s[i]) + 1) if ((sz + SZ(s[i])) % 2 == 0) {
      int s1 = 0, s2 = 0, m = sz + SZ(s[i]);
      fore(j, 0, m / 2) s1 += (int)(s[i][j] - '0');
      fore(j, m / 2, SZ(s[i])) s2 += (int)(s[i][j] - '0');

      ans += cnt[sz][s1 - s2];
      if (sz == SZ(s[i])) continue;

      s1 = 0, s2 = 0;
      for (int j = SZ(s[i]) - 1; j >= SZ(s[i]) - m / 2; j--)
        s1 += (int)(s[i][j] - '0');
      for (int j = SZ(s[i]) - m / 2 - 1; j >= 0; j--)
        s2 += (int)(s[i][j] - '0');

      ans += cnt[sz][s1 - s2];
    }
  }
  cout << ans << "\n";
  return 0;
}
