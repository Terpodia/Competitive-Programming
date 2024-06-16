#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

// MACROS
#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
// FOR
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
// DEBUG
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
typedef pair<ll, ll> pll;

bool cmp(pll x, pll y) {
  if (x.snd != y.snd) return x.snd < y.snd;
  return x.fst < y.fst;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    pll a[n];
    forn(i, n) cin >> a[i].fst;
    forn(i, n) cin >> a[i].snd;
    sort(a, a + n, cmp);

    ll pref[n + 1];
    pref[0] = 0;
    fore(i, 1, n + 1) pref[i] =
        pref[i - 1] + max(a[i - 1].snd - a[i - 1].fst, 0LL);

    ll ans = 0, cur = 0;
    set<pll> s;

    for (int i = n - 1; i >= n - k; i--) {
      cur += a[i].fst;
      s.insert({a[i].fst, i});
    }

    for (int i = n - k - 1; i >= 0; i--) {
      ans = max(ans, pref[i + 1] - cur);
      if (len(s) && s.rbegin()->fst > a[i].fst) {
        auto it = s.end();
        it--;
        cur -= it->fst;
        s.erase(it);
        s.insert({a[i].fst, i});
        cur += a[i].fst;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
