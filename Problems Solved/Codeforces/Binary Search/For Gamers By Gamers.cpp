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

const int MAXC = 1e6 + 10;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, C;
  cin >> n >> C;
  vector<ll> v(MAXC, 0), pref(MAXC + 1, 0);

  fore(i, 0, n) {
    int c;
    ll d, h;
    cin >> c >> d >> h;
    v[c] = max(v[c], d * h);
  }
  fore(i, 1, MAXC) {
    for (int j = 2 * i; j <= C; j += i) v[j] = max(v[j], v[i] * (ll)(j / i));
  }
  fore(i, 1, MAXC + 1) { pref[i] = max(pref[i - 1], v[i]); }
  int m;
  cin >> m;
  pair<ll, ll> monsters[m];
  fore(i, 0, m) cin >> monsters[i].fst >> monsters[i].snd;
  fore(i, 0, m) {
    auto it = upper_bound(all(pref), monsters[i].fst * monsters[i].snd);
    if (it == pref.end())
      cout << "-1 ";
    else
      cout << (int)distance(pref.begin(), it) << " ";
  }
  cout << "\n";
  return 0;
}
