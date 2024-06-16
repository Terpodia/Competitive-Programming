#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const ll P = 1777771, MOD[2] = {999727999, 1070777777};
struct Hash {
  vector<ll> h[2], pow[2];
  Hash() {}
  Hash(string &s) {
    fore(k, 0, 2) h[k] = vector<ll>(len(s) + 1, 0),
                  pow[k] = vector<ll>(len(s) + 1, 1);
    fore(k, 0, 2) fore(i, 1, len(s) + 1) {
      h[k][i] = (h[k][i - 1] * P + (ll)s[i - 1]) % MOD[k];
      pow[k][i] = (pow[k][i - 1] * P) % MOD[k];
    }
  }
  pair<ll, ll> get(int l, int r) {
    ll ret[2];
    fore(k, 0, 2) ret[k] =
        ((h[k][r] - pow[k][r - l] * h[k][l]) % MOD[k] + MOD[k]) % MOD[k];
    return {ret[0], ret[1]};
    // return (ret[0]<<32LL)|ret[1];
  }
  ll get2(int l, int r) {
    ll ret[2];
    fore(k, 0, 2) ret[k] =
        ((h[k][r] - pow[k][r - l] * h[k][l]) % MOD[k] + MOD[k]) % MOD[k];
    return (ret[0] << 32LL) | ret[1];
  }
};

int n, k;
string s;

void solve() {
  string t1 = "", t2 = "";
  char cur = '1';
  forn(i, n) {
    if (i % k == 0) cur = (cur == '1') ? '0' : '1';
    t1.pb(cur);
  }
  cur = '0';
  forn(i, n) {
    if (i % k == 0) cur = (cur == '1') ? '0' : '1';
    t2.pb(cur);
  }
  Hash h(t1);
  ll x = h.get2(0, n);
  h = Hash(t2);
  ll y = h.get2(0, n);

  string rs = s;
  reverse(all(rs));

  Hash h1(s);
  Hash h2(rs);

  forn(i, n) {
    pair<ll, ll> p1 = h1.get(i + 1, n);
    pair<ll, ll> p2 = h2.get(n - i - 1, n);

    ll z1 = 0, z2 = 0;
    z1 = ((p1.fst * h1.pow[0][i + 1]) % MOD[0] + p2.fst) % MOD[0];
    z2 = ((p1.snd * h1.pow[1][i + 1]) % MOD[1] + p2.snd) % MOD[1];
    ll z = (z1 << 32LL) | z2;

    if (x == z || y == z) {
      cout << i + 1 << "\n";
      return;
    }
  }

  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k >> s;
    solve();
  }
  return 0;
}
