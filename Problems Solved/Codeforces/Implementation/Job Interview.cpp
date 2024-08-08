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
  int n, m;
  cin >> n >> m;
  int k = n + m + 1;
  ll a[k], b[k];
  forn(i, k) cin >> a[i];
  forn(i, k) cin >> b[i];

  pair<int, int> cnt[k + 1];
  cnt[0] = {0, 0};
  fore(i, 1, k + 1) {
    cnt[i] = cnt[i - 1];
    if (a[i - 1] > b[i - 1]) {
      if (cnt[i].fst < n)
        cnt[i].fst++;
      else
        cnt[i].snd++;
    } else {
      if (cnt[i].snd < m)
        cnt[i].snd++;
      else
        cnt[i].fst++;
    }
  }

  ll pref[3][k + 1];
  pref[0][0] = pref[1][0] = pref[2][0] = 0;

  fore(i, 1, k + 1) {
    ll x = a[i - 1], y = b[i - 1];
    pref[0][i] = pref[0][i - 1];
    if (x > y) {
      if (cnt[i - 1].fst < n)
        pref[0][i] += x;
      else
        pref[0][i] += y;
    } else {
      if (cnt[i - 1].snd < m)
        pref[0][i] += y;
      else
        pref[0][i] += x;
    }
  }
  pair<int, int> cur = {0, 0};
  fore(i, 1, k + 1) {
    ll x = a[i - 1], y = b[i - 1];
    pref[1][i] = pref[1][i - 1];
    if (x > y) {
      if (cur.fst < n + 1)
        cur.fst++, pref[1][i] += x;
      else
        cur.snd++, pref[1][i] += y;
    } else {
      if (cur.snd < m)
        cur.snd++, pref[1][i] += y;
      else
        cur.fst++, pref[1][i] += x;
    }
  }
  cur = {0, 0};
  fore(i, 1, k + 1) {
    ll x = a[i - 1], y = b[i - 1];
    pref[2][i] = pref[2][i - 1];
    if (x > y) {
      if (cur.fst < n)
        cur.fst++, pref[2][i] += x;
      else
        cur.snd++, pref[2][i] += y;
    } else {
      if (cur.snd < m + 1)
        cur.snd++, pref[2][i] += y;
      else
        cur.fst++, pref[2][i] += x;
    }
  }

  fore(i, 1, k + 1) {
    ll res = pref[0][i - 1];
    if (a[i - 1] > b[i - 1]) {
      if (cnt[i - 1].fst < n)
        res += pref[1][k] - pref[1][i];
      else
        res += pref[2][k] - pref[2][i];
    } else {
      if (cnt[i - 1].snd < m)
        res += pref[2][k] - pref[2][i];
      else
        res += pref[1][k] - pref[1][i];
    }
    cout << res << " ";
  }
  cout << "\n";
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
