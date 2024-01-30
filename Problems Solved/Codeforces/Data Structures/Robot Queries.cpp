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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  pair<int, int> p[n + 1];
  p[0] = mp(0, 0);
  fore(i, 1, n + 1) {
    p[i] = p[i - 1];
    if (s[i - 1] == 'U')
      p[i].snd++;
    else if (s[i - 1] == 'D')
      p[i].snd--;
    else if (s[i - 1] == 'R')
      p[i].fst++;
    else
      p[i].fst--;
  }

  map<pair<int, int>, vector<int>> m;
  fore(i, 0, n + 1) m[p[i]].push_back(i);

  while (q--) {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    if (m.find(mp(x, y)) != m.end() && m[mp(x, y)][0] < l)
      cout << "YES\n";
    else if (m.find(mp(x, y)) != m.end() && m[mp(x, y)].back() > r)
      cout << "YES\n";
    else {
      int xx = -x + p[l - 1].fst + p[r].fst;
      int yy = -y + p[l - 1].snd + p[r].snd;
      if (m.find(mp(xx, yy)) != m.end()) {
        auto it = lower_bound(all(m[mp(xx, yy)]), l - 1);
        if (it != m[mp(xx, yy)].end() && *it <= r)
          cout << "YES\n";
        else
          cout << "NO\n";
      } else
        cout << "NO\n";
    }
  }

  return 0;
}
