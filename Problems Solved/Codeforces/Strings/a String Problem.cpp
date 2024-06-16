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
  ll get(int l, int r) {
    ll ret[2];
    fore(k, 0, 2) ret[k] =
        ((h[k][r] - pow[k][r - l] * h[k][l]) % MOD[k] + MOD[k]) % MOD[k];
    return (ret[0] << 32LL) | ret[1];
  }
};

string s;

void solve() {
  int n = len(s);
  int nxt[n + 1];
  ll pref[n + 1];
  forn(i, n + 1) nxt[i] = n;
  int j = n;
  dfor(i, n) {
    if (s[i] != 'a') j = i;
    nxt[i] = j;
  }
  pref[0] = 0;
  fore(i, 1, n + 1) {
    pref[i] = pref[i - 1];
    if (s[i - 1] == 'a') pref[i]++;
  }

  Hash h(s);
  ll ans = 0;
  fore(k, 1, n + 1) {
    j = nxt[0];
    if (j + k - 1 >= n) break;

    ll cnt = j;
    bool can = true;
    ll val = h.get(j, j + k);
    while (j < len(s)) {
      if (j + k - 1 >= n) {
        can = false;
        break;
      }
      can &= h.get(j, j + k) == val;
      if (nxt[j + k] < n) cnt = min(cnt, pref[nxt[j + k]] - pref[j + k]);
      j = nxt[j + k];
    }
    if (can) ans += cnt + 1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    bool flag = true;
    for (char c : s) flag &= c == 'a';
    if (flag)
      cout << len(s) - 1 << "\n";
    else
      solve();
  }
  return 0;
}
