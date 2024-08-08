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

const int MAXK = 2e5 + 10;

ll n, m;
int k;
pair<ll, ll> a[MAXK];

ll area(pair<ll, ll> x, pair<ll, ll> y) {
  return (abs(x.fst - y.fst) + 1LL) * (abs(x.snd - y.snd) + 1LL);
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
  if (x.snd != y.snd) return x.snd < y.snd;
  return x.fst < y.fst;
}

void solve() {
  pair<ll, ll> cur = {1, 1};

  pair<ll, ll> b[k];
  forn(i, k) b[i] = a[i];

  sort(a, a + k, cmp);
  ll ans = 0;

  map<ll, ll> cnt;
  set<pair<ll, ll>> s;

  forn(i, k) {
    if (a[i].snd == 1) {
      cur.fst = a[i].fst + 1;
      cnt[a[i].snd] = max(cnt[a[i].snd], a[i].fst);
      s.insert(a[i]);
      continue;
    }
    if (a[i].fst < cur.fst) continue;
    s.insert(a[i]);
    cnt[a[i].snd] = max(cnt[a[i].snd], a[i].fst);

    pair<ll, ll> x = {a[i].fst, a[i].snd - 1};
    ans += area(cur, x);

    cur.fst = a[i].fst + 1;
  }
  if (cur.fst <= n) {
    pair<ll, ll> x = {n, m};
    ans += area(cur, x);
  }
  cout << ans << "\n";
  forn(i, k) {
    if (s.find(b[i]) == s.end())
      cout << "0 ";
    else {
      if (cnt[b[i].snd] == b[i].fst)
        cout << "1 ";
      else
        cout << "0 ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> k;
    forn(i, k) cin >> a[i].fst >> a[i].snd;
    solve();
  }
  return 0;
}
