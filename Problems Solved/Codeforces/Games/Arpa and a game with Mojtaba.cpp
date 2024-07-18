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

const int MAXN = 1e7 + 10;
int cr[MAXN];
vector<ll> p;
void init_sieve() {
  for (int i = 2; i < MAXN; i += 2) cr[i] = 2;
  p.pb(2);
  for (int i = 3; i < MAXN; i += 2)
    if (!cr[i]) {
      p.pb(i), cr[i] = i;
      for (ll j = 1LL * i * i; j < MAXN; j += i) cr[j] = i;
    }
}
map<ll, int> fact(ll n) {
  map<ll, int> ret;
  if (n < MAXN) {
    while (n > 1) ret[cr[n]]++, n /= cr[n];
    return ret;
  }
  for (int i = 0; i < len(p) && p[i] * p[i] <= n; i++) {
    while (n % p[i] == 0) ret[p[i]]++, n /= p[i];
  }
  if (n > 1) ret[n]++;
  return ret;
}

int n;
vector<int> a;

unordered_map<int, int> dp;

int g(int msk) {
  if (dp.find(msk) != dp.end()) return dp[msk];
  if (msk == 0) return dp[msk] = 0;
  vector<int> res;

  int m = 0;
  forn(i, 31) if (msk & (1 << i)) m = i;

  forn(i, m + 1) {
    int nmsk = (msk >> (i + 1)) | (msk & ((1 << i) - 1));
    res.push_back(g(nmsk));
  }
  sort(all(res));
  res.resize(distance(res.begin(), unique(all(res))));
  int cur = 0;
  for (int i : res) {
    if (i != cur) return dp[msk] = cur;
    cur++;
  }
  return dp[msk] = cur;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init_sieve();
  cin >> n;
  a = vector<int>(n);
  forn(i, n) cin >> a[i];
  map<int, int> v;

  forn(i, n) {
    map<ll, int> f = fact(a[i]);
    for (auto [x, y] : f) {
      v[x] |= (1 << (y - 1));
    }
  }
  for (auto &[i, j] : v) {
    j = g(j);
  }

  int ans = 0;
  for (auto [i, j] : v) ans ^= j;
  if (ans > 0)
    cout << "Mojtaba\n";
  else
    cout << "Arpa\n";
  return 0;
}
