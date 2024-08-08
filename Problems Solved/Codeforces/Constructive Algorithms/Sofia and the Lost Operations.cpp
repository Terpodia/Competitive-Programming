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
  cin >> n;
  int a[n], b[n];
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];
  int m;
  cin >> m;
  int d[m];
  forn(i, m) cin >> d[i];

  set<int> e;
  forn(i, n) e.insert(b[i]);

  map<int, int> bad;
  forn(i, n) if (a[i] != b[i]) bad[b[i]]++;

  bool flag = false;
  forn(i, m) {
    if (e.find(d[i]) == e.end()) {
      if (len(bad) > 0) continue;
      flag = true;
    } else {
      if (len(bad) > 0) {
        if (bad.find(d[i]) != bad.end()) {
          bad[d[i]]--;
          if (bad[d[i]] == 0) bad.erase(d[i]);
        }
      } else
        flag = false;
    }
  }

  if (len(bad) == 0 && !flag)
    cout << "YES\n";
  else
    cout << "NO\n";
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
