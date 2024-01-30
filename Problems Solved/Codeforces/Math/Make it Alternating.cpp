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

const ll MOD = 998244353;
const int MAXN = 2e5 + 10;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll fact[MAXN];
  fact[0] = 1;
  fore(i, 1, MAXN) fact[i] = ((ll)i * fact[i - 1]) % MOD;

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = SZ(s);
    int ls0 = 0, ls1 = 0;
    ll seg0[n], seg1[n];
    memset(seg0, 0, sizeof(seg0));
    memset(seg1, 0, sizeof(seg1));
    ll cnt = 0;
    for (char c : s) {
      if (c == '0')
        cnt++;
      else
        seg0[ls0++] = cnt, cnt = 0;
    }
    if (cnt != 0) seg0[ls0++] = cnt;
    cnt = 0;
    for (char c : s) {
      if (c == '1')
        cnt++;
      else
        seg1[ls1++] = cnt, cnt = 0;
    }
    if (cnt != 0) seg1[ls1++] = cnt;
    ll ans = 1, m = n;
    cnt = 0;
    fore(i, 0, ls0) {
      if (seg0[i] == 0) continue;
      cnt += seg0[i] - 1;
      m--;
      ans = (ans * seg0[i]) % MOD;
    }
    fore(i, 0, ls1) {
      if (seg1[i] == 0) continue;
      cnt += seg1[i] - 1;
      m--;
      ans = (ans * seg1[i]) % MOD;
    }
    ans = (ans * fact[m]) % MOD;
    cout << cnt << " " << ans << "\n";
  }
  return 0;
}
