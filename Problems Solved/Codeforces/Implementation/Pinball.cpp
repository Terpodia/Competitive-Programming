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
    string s;
    cin >> s;
    deque<int> l, r;
    vector<ll> p1(n + 10, 0), p2(n + 10, 0);
    fore(i, 0, n) {
      if (s[i] == '<') r.push_back(i);
    }
    r.push_back(n);
    fore(i, 1, SZ(r) + 1) p1[i] = p1[i - 1] + r[i - 1];
    int j = 0;

    l.push_back(-1);
    p2[1] = -1;

    fore(i, 0, n) {
      if (s[i] == '<') r.pop_front(), j++;
      int k = min(SZ(l), SZ(r));

      ll ans = 0;
      if (s[i] == '>') {
        if (SZ(l) >= SZ(r)) {
          ans += (p1[j + k] - p1[j]) * 2 - (ll)n;
          ans -= (p2[SZ(l)] - p2[SZ(l) - k + 1]) * 2 + (ll)i;
        } else {
          ans += (p1[j + k] - p1[j]) * 2;
          ans -= (p2[SZ(l)] - p2[SZ(l) - k]) * 2 + 1 + (ll)i;
        }
      } else {
        if (SZ(r) >= SZ(l)) {
          ans += (p1[j + k - 1] - p1[j]) * 2 + (ll)i;
          ans -= (p2[SZ(l)] - p2[SZ(l) - k]) * 2 + 1;
        } else {
          ans += (p1[j + k] - p1[j]) * 2 + (ll)i - (ll)n;
          ans -= (p2[SZ(l)] - p2[SZ(l) - k]) * 2;
        }
      }
      cout << ans << " ";

      if (s[i] == '>') l.push_front(i), p2[SZ(l)] = p2[SZ(l) - 1] + (ll)l[0];
    }
    cout << "\n";
  }
  return 0;
}
