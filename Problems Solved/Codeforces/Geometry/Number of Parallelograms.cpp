//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef unsigned long long u64;

struct point_ll {
  ll x, y;
  point_ll() {}
  point_ll(ll _x, ll _y) : x(_x), y(_y) {}
};

int n;
point_ll p[2000];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  rep(i, 0, n) cin >> p[i].x >> p[i].y;

  map<tuple<ll, ll, ll>, u64> mp;

  rep(i, 0, n) rep(j, i + 1, n) {
    ll dist = (p[i].x - p[j].x) * (p[i].x - p[j].x) +
              (p[i].y - p[j].y) * (p[i].y - p[j].y);

    if (p[i].x == p[j].x) {
      mp[make_tuple(1, 0, dist)]++;
    } else {
      ll a = p[j].y - p[i].y;
      ll b = p[i].x - p[j].x;

      if (a < 0)
        a *= -1, b *= -1;
      else if (a == 0 && b < 0)
        b *= -1;

      mp[make_tuple(a, b, dist)]++;
    }
  }

  u64 ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->snd > 1) ans += (it->snd * (it->snd - (u64)1)) / (u64)2;
  }
  ans /= (u64)2;

  cout << ans << "\n";

  return 0;
}
