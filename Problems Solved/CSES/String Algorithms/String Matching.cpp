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
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;

struct Hash {
  ll P = 1777771, MOD[2];
  vector<ll> h[2], pow[2];
  Hash(string& s) {
    MOD[0] = 999727999, MOD[1] = 1070777777;
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string t, p;
  cin >> t >> p;
  Hash h1(t), h2(p);
  int l = 0, r = SZ(p), cnt = 0;

  while (r <= SZ(t)) {
    if (h1.get(l, r) == h2.get(0, SZ(p))) cnt++;
    l++, r++;
  }
  cout << cnt << "\n";
  return 0;
}
