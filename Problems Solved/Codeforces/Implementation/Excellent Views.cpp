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

const int MAXN = 1e5 + 100;

int n, h[MAXN], acc[MAXN];

bool cmp(pair<int, int> x, pair<int, int> y) { return x.fst > y.fst; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fore(i, 0, n) cin >> h[i];

  pair<int, int> a[n];
  fore(i, 0, n) a[i] = mp(h[i], i);
  sort(a, a + n, cmp);

  set<int> s;

  fore(i, 0, n) {
    s.insert(a[i].snd);
    auto it = s.find(a[i].snd);
    if (it != s.begin()) {
      it--;
      // if(a[i].fst == 5) dbg(a[i].snd);
      acc[(a[i].snd + *it) / 2 + 1]++;
      acc[a[i].snd]--;
      it++;
    } else
      acc[0]++, acc[a[i].snd]--;

    it++;
    if (it != s.end()) {
      // if(a[i].fst == 5) dbg(a[i].snd);
      acc[a[i].snd + 1]++;
      acc[(a[i].snd + *it + 1) / 2]--;
    } else
      acc[a[i].snd + 1]++, acc[n]--;
  }

  int sum = 0;
  fore(i, 0, n) {
    sum += acc[i];
    cout << sum << " ";
  }
  cout << "\n";
  return 0;
}
