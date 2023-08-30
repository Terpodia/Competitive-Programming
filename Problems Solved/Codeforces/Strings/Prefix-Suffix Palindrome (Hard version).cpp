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

const ll P = 1777771, MOD[2] = {(ll)1e9 + 7LL, 1070777777};
struct Hash {
  vector<ll> h[2], pow[2];
  Hash() {}
  Hash(string& s) {
    fore(k, 0, 2) h[k] = vector<ll>(SZ(s) + 1, 0),
                  pow[k] = vector<ll>(SZ(s) + 1, 1);
    fore(k, 0, 2) fore(i, 1, SZ(s) + 1) {
      h[k][i] = ((h[k][i - 1] * P) % MOD[k] + s[i - 1]) % MOD[k];
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

string s;

pair<int, int> pref(int l, int r) {
  string t = s.substr(l, r - l + 1);
  string p = t;
  reverse(all(p));

  Hash ht(t), hp(p);
  int ret = 0;
  fore(i, 1, SZ(t)) {
    if (2 * i < SZ(t)) {
      if (ht.get(0, i) == hp.get(SZ(t) - 1 - 2 * i, SZ(t) - 1 - i - 1 + 1) &&
          2 * i > ret)
        ret = 2 * i;
    }
    if (t[i] == t[i - 1] && 2 * i - 1 < SZ(t)) {
      if (ht.get(0, i - 1) ==
              hp.get(SZ(t) - 1 - 2 * i + 1, SZ(t) - 1 - i - 1 + 1) &&
          2 * i - 1 > ret)
        ret = 2 * i - 1;
    }
  }
  return mp(l, ret + l);
}
pair<int, int> suff(int l, int r) {
  string t = s.substr(l, r - l + 1);
  string p = t;
  reverse(all(p));

  Hash ht(t), hp(p);

  int ret = SZ(t) - 1;

  for (int i = SZ(t) - 2; i >= 0; i--) {
    int cnt = SZ(t) - 1 - i;
    if (i - cnt >= 0) {
      if (ht.get(i + 1, SZ(t)) ==
              hp.get(SZ(t) - 1 - i + 1, SZ(t) - 1 - i + cnt + 1) &&
          i - cnt < ret)
        ret = i - cnt;
    }
    if (t[i] == t[i + 1] && i - cnt + 1 >= 0) {
      if (ht.get(i + 2, SZ(t)) ==
              hp.get(SZ(t) - 1 - i + 1, SZ(t) - 1 - i + cnt - 1 + 1) &&
          i - cnt + 1 < ret)
        ret = i - cnt + 1;
    }
  }
  return mp(ret + l, r);
}

void solve() {
  int l = 0, r = SZ(s) - 1;
  while (l < r) {
    if (s[l] == s[r])
      l++, r--;
    else
      break;
  }
  dbg(SZ(s));
  raya;
  if (l >= r) {
    cout << s.substr(1, SZ(s) - 2) << "\n";
    return;
  }
  pair<int, int> p1, p2;
  p1 = pref(l, r), p2 = suff(l, r);
  pair<int, int> p = (p1.snd - p1.fst > p2.snd - p2.fst) ? p1 : p2;

  string t = s.substr(0, l) + s.substr(p.fst, p.snd - p.fst + 1) +
             s.substr(r + 1, SZ(s) - r);
  cout << t.substr(1, SZ(t) - 2) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    s = "$" + s;
    s += "$";
    solve();
  }
  return 0;
}
