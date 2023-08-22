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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    ll n = 0, acc = 1, curr = 0, m = 0;
    fore(i, (ll)1, (ll)19) {
      m = curr, n = i;
      acc *= 10LL;
      curr += (acc - acc / 10LL) * i;
      if (k <= curr) break;
    }
    ll x = k - m - 1;
    ll ans = acc / 10LL + x / n;
    string s = to_string(ans);
    cout << s[x % n] << "\n";
  }
  return 0;
}
