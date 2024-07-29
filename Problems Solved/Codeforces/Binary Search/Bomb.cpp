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

const ll INF = 1e15;

const int MAXN = 2e5 + 10;

int n;
ll k, a[MAXN], b[MAXN];

bool f(ll x) {
  ll cnt = 0;
  forn(i, n) if (a[i] >= x) { cnt += (a[i] - x) / b[i] + 1LL; }
  return cnt <= k;
}

ll bs() {
  ll l = 0, r = INF;
  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (f(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

void solve() {
  cin >> n >> k;
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];

  ll ans = 0;
  ll x = bs();

  forn(i, n) if (a[i] >= x) {
    ll y = (a[i] - x) / b[i] + 1LL;
    k -= y;
    ans += a[i] * y - b[i] * ((y * (y - 1LL)) / 2LL);
    a[i] -= y * b[i];
  }
  priority_queue<pair<ll, int>> pq;
  forn(i, n) pq.push(make_pair(a[i], i));
  while (!pq.empty()) {
    if (k == 0) break;
    auto [val, idx] = pq.top();
    pq.pop();
    if (val < 0) break;
    k--;
    ans += a[idx];
    a[idx] -= b[idx];
    pq.push(make_pair(a[idx], idx));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
