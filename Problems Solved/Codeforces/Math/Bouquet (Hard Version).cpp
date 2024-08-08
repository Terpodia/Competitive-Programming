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

void solve() {
  int n;
  ll m;
  cin >> n >> m;
  ll a[n];
  forn(i, n) cin >> a[i];
  map<ll, ll> cnt;
  forn(i, n) {
    ll c;
    cin >> c;
    cnt[a[i]] = c;
  }
  ll ans = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    ans = max(ans, it->fst * min(it->snd, (m / it->fst)));

    auto it2 = next(it);
    if (it2 == cnt.end()) break;
    if (it2->fst != it->fst + 1) continue;

    ll res = 0, k = m;

    if (k > it2->fst * it2->snd + it->fst * it->snd)
      res = it2->fst * it2->snd + it->fst * it->snd;
    else {
      ll res1 = 0, res2 = 0, res3 = 0;

      ll x = min(it->snd, k / it->fst);
      k -= it->fst * x;
      ll r = k % it2->fst;
      ll d = min(r, min(x, (it2->snd * it2->fst - k) / it->fst));

      x -= d, k += it->fst * d;
      res1 += it->fst * x;

      ll y = min(it2->snd, k / it2->fst);
      res1 += it2->fst * y;

      k = m;
      x = min(it2->snd, k / it2->fst);
      res2 += x * it2->fst, k -= it2->fst * x;
      res2 += min(it->snd, k / it->fst) * it->fst;

      k = m;
      r = (k - it2->fst * x) % it->fst;
      if (r > 0) r = it->fst - r;
      x -= min(x, r);
      res3 += x * it2->fst, k -= it2->fst * x;
      res3 += min(it->snd, k / it->fst) * it->fst;

      res = max(res1, max(res2, res3));
    }
    ans = max(ans, res);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
