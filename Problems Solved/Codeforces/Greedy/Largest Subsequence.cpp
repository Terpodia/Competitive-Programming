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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s, k;
    cin >> s;
    k = s;
    sort(all(k));

    int suff[n + 1];
    suff[n] = 0;
    for (int i = n - 1; i >= 0; i--) suff[i] = max(suff[i + 1], (int)s[i]);

    int ans = 0, hi = suff[0];

    vector<int> pos;
    fore(i, 0, n) {
      if (s[i] != suff[i]) continue;
      if (suff[i] != hi) ans++;
      pos.pb(i);
    }
    string t;
    int cur = 0;
    fore(i, 0, n) {
      if (i != pos[cur])
        t.pb(s[i]);
      else
        t.pb(s[pos[SZ(pos) - 1 - cur]]), cur++;
    }
    if (t == k)
      cout << ans << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
