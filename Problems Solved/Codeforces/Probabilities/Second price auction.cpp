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
#define erof(i, x, n) for (auto i = (x); i > (n); i--)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]

typedef long double ld;

int power(int n) {
  int ret = 1;
  fore(i, 0, n) ret *= 3;
  return ret;
}

int get(int a, int b) { return (a / power(b)) % 3; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(13);
  int n;
  cin >> n;
  pair<int, int> a[n];
  fore(i, 0, n) cin >> a[i].fst >> a[i].snd;
  ld ans = 0;
  fore(b, 1, 10001) {
    fore(msk, 0, power(n)) {
      int cnt1 = 0, cnt2 = 0;
      fore(i, 0, n) {
        if (get(msk, i) == 1) cnt1++;
        if (get(msk, i) == 2) cnt2++;
      }
      if (cnt2 > 1 || cnt1 == 0) continue;
      if (cnt2 == 0 && cnt1 < 2) continue;
      ld p = 1;
      fore(i, 0, n) {
        int l = a[i].fst, r = a[i].snd;
        if (get(msk, i) == 0)
          r = min(r, b - 1);
        else if (get(msk, i) == 2)
          l = max(l, b + 1);
        else {
          if (!(l <= b && b <= r)) {
            p = 0;
            break;
          }
          l = r = b;
        }
        if (l > r) {
          p = 0;
          break;
        }
        p *= (ld)(r - l + 1) / (ld)(a[i].snd - a[i].fst + 1);
      }
      ans += (ld)b * p;
    }
  }
  cout << ans << "\n";
  return 0;
}
