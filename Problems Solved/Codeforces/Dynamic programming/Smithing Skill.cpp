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

const int MAXN = 1e6 + 10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  pair<int, int> p[n];
  int c[m];
  forn(i, n) cin >> p[i].snd;
  forn(i, n) {
    int b;
    cin >> b;
    p[i].fst = p[i].snd - b;
  }
  sort(p, p + n);
  int pref[n + 1];
  pref[0] = MAXN;
  fore(i, 1, n + 1) pref[i] = min(pref[i - 1], p[i - 1].snd);
  forn(i, m) cin >> c[i];

  vector<ll> dp(MAXN, 0);
  dfor(i, n) {
    fore(j, p[i].snd, pref[i]) {
      ll k = (j - p[i].snd) / p[i].fst + 1;
      dp[j] += k + dp[j - p[i].fst * k];
    }
  }

  ll ans = 0;
  forn(i, m) {
    if (c[i] >= p[0].snd) {
      ll k = (c[i] - p[0].snd) / p[0].fst + 1;
      ans += k;
      c[i] -= p[0].fst * k;
    }
    ans += dp[c[i]];
  }
  cout << ans * 2LL << "\n";
  return 0;
}
