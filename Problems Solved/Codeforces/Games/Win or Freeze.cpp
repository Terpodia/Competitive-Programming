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

const int MAXN = 1e7 + 10;

int cr[MAXN];
vector<ll> p;
void init_sieve() {
  for (int i = 2; i < MAXN; i += 2) cr[i] = 2;
  p.pb(2);
  for (int i = 3; i < MAXN; i += 2)
    if (!cr[i]) {
      p.pb(i), cr[i] = i;
      for (ll j = 1LL * i * i; j < MAXN; j += i) cr[j] = i;
    }
}
map<ll, int> fact(ll n) {
  map<ll, int> ret;
  for (int i = 0; i < SZ(p) && p[i] * p[i] <= n; i++) {
    while (n % p[i] == 0) ret[p[i]]++, n /= p[i];
  }
  if (n > 1) ret[n]++;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init_sieve();
  ll q;
  cin >> q;
  map<ll, int> f = fact(q);
  int cnt = 0;
  for (auto& [x, y] : f) cnt += y;
  if (q == 1 || cnt == 1) {
    cout << "1\n0\n";
    return 0;
  }
  if (cnt == 2) {
    cout << "2\n";
    return 0;
  }
  ll ans = 1;
  cnt = 0;
  for (auto& [x, y] : f) {
    if (cnt == 2) break;
    int v = y;
    while (v > 0 && cnt < 2) ans *= x, v--, cnt++;
  }
  cout << "1\n" << ans << "\n";
  return 0;
}
