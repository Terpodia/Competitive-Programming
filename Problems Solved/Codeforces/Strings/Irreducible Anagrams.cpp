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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = len(s);

  int pref[26][n + 1];
  forn(i, 26) pref[i][0] = 0;

  forn(c, 26) {
    fore(i, 1, n + 1) {
      pref[c][i] = pref[c][i - 1];
      if (c + 'a' == s[i - 1]) pref[c][i]++;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;

    if (r - l == 0) {
      cout << "Yes\n";
      continue;
    }
    if (s[l] != s[r]) {
      cout << "Yes\n";
      continue;
    }
    int cnt = 0;
    forn(c, 26) {
      if (pref[c][r + 1] - pref[c][l] > 0) cnt++;
    }
    if (cnt > 2)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
