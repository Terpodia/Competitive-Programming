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

const int INF = 1e9;

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

struct HashWeird {
  vector<ll> h[2][26], pow[2];
  HashWeird() {}
  HashWeird(string &s) {
    fore(k, 0, 2) fore(c, 0, 26) h[k][c] = vector<ll>(len(s) + 1, 0);
    fore(k, 0, 2) pow[k] = vector<ll>(len(s) + 1, 1);

    fore(k, 0, 2) fore(i, 1, len(s) + 1) {
      pow[k][i] = (pow[k][i - 1] * P) % MOD[k];
    }
    fore(k, 0, 2) fore(c, 0, 26) fore(i, 1, len(s) + 1) {
      if (s[i - 1] - 'a' == c)
        h[k][c][i] = (h[k][c][i - 1] * P + 1LL) % MOD[k];
      else
        h[k][c][i] = (h[k][c][i - 1] * P + 0LL) % MOD[k];
    }
  }
  pair<ll, ll> get(int l, int r, int c) {
    ll ret[2];
    fore(k, 0, 2) ret[k] =
        ((h[k][c][r] - pow[k][r - l] * h[k][c][l]) % MOD[k] + MOD[k]) % MOD[k];
    return make_pair(ret[0], ret[1]);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;

  int nxt[26][n];
  memset(nxt, -1, sizeof(nxt));
  forn(c, 26) {
    dfor(i, n) {
      if (i < n - 1) nxt[c][i] = nxt[c][i + 1];
      if (s[i] - 'a' == c) {
        nxt[c][i] = i;
      }
    }
  }

  Hash h(s);
  HashWeird w(s);

  while (m--) {
    int x, y, l;
    cin >> x >> y >> l;

    x--, y--;

    int l1 = x, r1 = x + l - 1;
    int l2 = y, r2 = y + l - 1;

    ll target = h.get(l2, r2 + 1);
    ll val1 = 0, val2 = 0;

    vector<bool> vis(26, false);
    bool can = true;

    forn(c, 26) {
      int pos = nxt[c][l1];
      if (pos <= r1 && pos >= l1) {
        ll to = s[pos - l1 + l2];
        if (vis[to - 'a']) can = false;
        vis[to - 'a'] = true;
        pair<ll, ll> p = w.get(l1, r1 + 1, c);
        val1 += (p.fst * to) % MOD[0], val2 += (p.snd * to) % MOD[1];
        val1 %= MOD[0], val2 %= MOD[1];
      }
    }

    ll val = (val1 << 32LL) | val2;

    if (target == val && can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
