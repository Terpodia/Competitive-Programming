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

const ll P = 1777771, MOD[2] = {999727999, 1070777777};
struct Hash {
  vector<ll> h[2], pow[2];
  Hash() {}
  Hash(string& s) {
    fore(k, 0, 2) h[k] = vector<ll>(SZ(s) + 1, 0),
                  pow[k] = vector<ll>(SZ(s) + 1, 1);
    fore(k, 0, 2) fore(i, 1, SZ(s) + 1) {
      h[k][i] = (h[k][i - 1] * P + (ll)s[i - 1]) % MOD[k];
      pow[k][i] = (pow[k][i - 1] * P) % MOD[k];
    }
  }
  ll get(int l, int r) {
    ll ret[2];
    fore(k, 0, 2) ret[k] =
        ((h[k][r] - pow[k][r - l] * h[k][l]) % MOD[k] + MOD[k]) % MOD[k];
    return (ret[0] << 32LL) | ret[1];
  }
};

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s;
    t = s;
    reverse(all(t));
    Hash h1(s), h2(t);

    int a[n], b[n], p1[n + 1], p2[n + 1];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(p1, 0, sizeof(p1));
    memset(p2, 0, sizeof(p2));

    for (int i = n - 2; i >= 0; i--) {
      if (s[i] != s[i + 1]) a[i]++;
    }
    fore(i, 1, n + 1) p1[i] = p1[i - 1] + a[i - 1];

    for (int i = n - 3; i >= 0; i -= 2)
      if (s[i] != s[i + 2]) b[i]++;
    for (int i = n - 4; i >= 0; i -= 2)
      if (s[i] != s[i + 2]) b[i]++;
    fore(i, 1, n + 1) p2[i] = p2[i - 1] + b[i - 1];

    while (q--) {
      int l, r;
      cin >> l >> r;
      ll ans = 0;
      if (h1.get(l - 1, r) != h2.get(n - r, n - r + (r - l + 1)))
        ans += r - l + 1;

      if (r - l + 1 <= 2) {
        cout << ans << "\n";
        continue;
      }

      if (p1[r] - p1[l - 1] - (r < n && s[r - 1] != s[r]) > 0) {
        ll m = (r - l + 2) / 2 - 1;
        ll k = 2LL * m;
        // dbg(l); dbg(r); dbg(m); dbg(k);
        ans += (m * (2LL + k)) / 2LL;
      }

      if (r - l + 1 <= 3) {
        cout << ans << "\n";
        continue;
      }

      ll cnt = 0;
      if (r + 1 < n && s[r - 1] != s[r + 1]) cnt++;
      if (r < n && s[r - 2] != s[r]) cnt++;

      // dbg(l); dbg(r); dbg(p2[r]-p2[l-1]-cnt);

      if (p2[r] - p2[l - 1] - cnt > 0) {
        ll m = (r - l + 1) / 2 + 1 - 2;
        ll k = 2LL * m + 1;
        // dbg(l); dbg(r); dbg(m); dbg(k);
        ans += (m * (3LL + k)) / 2LL;
      }

      cout << ans << "\n";
    }
  }
  return 0;
}
