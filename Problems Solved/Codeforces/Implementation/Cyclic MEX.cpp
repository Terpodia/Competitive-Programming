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
    ll p[n];
    fore(i, 0, n) cin >> p[i];
    vector<bool> f(n + 10, false);
    ll mex = 0, cur = 0, ans;
    deque<pair<ll, ll>> d;
    fore(i, 0, n) {
      f[p[i]] = true;
      while (f[mex]) mex++;
      d.push_back(mp(mex, 1));
      cur += mex;
    }
    ans = cur;
    fore(i, 0, n - 1) {
      ll cnt = 0;
      cur -= d[0].fst;
      d[0].snd--;
      while (!d.empty() && d.back().fst > p[i]) {
        cur -= d.back().fst * d.back().snd;
        cnt += d.back().snd;
        d.pop_back();
      }
      cur += p[i] * cnt;
      if (cnt > 0) d.push_back(mp(p[i], cnt));
      cur += n;
      if (d[0].snd == 0) d.pop_front();
      d.push_back(mp(n, 1));
      ans = max(ans, cur);
    }
    cout << ans << "\n";
  }
  return 0;
}
