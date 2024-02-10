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

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.snd != b.snd) return a.snd < b.snd;
  return a.fst < b.fst;
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
    int l[n], r[n];
    fore(i, 0, n) cin >> l[i] >> r[i];
    vector<pair<int, int>> v;

    fore(i, 0, n) fore(j, i + 1, n) {
      if (l[i] > r[j] || r[i] < l[j]) continue;
      v.pb(mp(min(l[i], l[j]), max(r[i], r[j])));
    }
    sort(all(v), cmp);
    int m = 0, cur = -1;
    fore(i, 0, SZ(v)) {
      if (v[i].fst > cur) m++, cur = v[i].snd;
    }
    cout << n - m * 2 << "\n";
  }
  return 0;
}
