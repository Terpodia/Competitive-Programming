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

  int n;
  string s;
  cin >> n >> s;
  int r = 0, k = 0;
  for (char c : s) {
    if (c == '+')
      r++;
    else
      k++;
  }
  int q;
  cin >> q;
  while (q--) {
    ll a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);

    if (a == b) {
      if (r != k)
        cout << "NO\n";
      else
        cout << "YES\n";
      continue;
    }
    ll c = b * k - b * r;
    ll g = a - b;
    if (abs(c) % g != 0) {
      cout << "NO\n";
      continue;
    }
    ll x = 0, y = c / (b - a);

    if (y < 0) {
      ll u = (a - b) / g, v = (b - a) / g;
      ll w = -y / u;
      x -= w * v, y += w * u;
    }
    if (y > k) {
      ll u = (a - b) / g, v = (b - a) / g;
      ll w = (k - y) / u;
      x += w * v, y -= w * u;
    }
    if (x > r) {
      ll u = (a - b) / g, v = (b - a) / g;
      ll w = (r - x) / v;
      x -= w * v, y += w * u;
    }
    if (x < 0) {
      ll u = (a - b) / g, v = (b - a) / g;
      ll w = -x / v;
      x += w * v, y -= w * u;
    }

    if (x < 0 || x > r || y < 0 || y > k)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
