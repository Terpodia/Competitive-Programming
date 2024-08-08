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

const int MAXN = 2e5 + 10;

int a[MAXN], n;

bool f(int idx) {
  if (idx >= n) return false;
  vector<int> v;
  forn(i, n) if (i != idx) v.pb(a[i]);
  // dbg(v);
  vector<int> r1;
  forn(i, len(v) - 1) r1.pb(__gcd(v[i], v[i + 1]));
  vector<int> r2 = r1;
  sort(all(r2));
  return r1 == r2;
}

void solve() {
  cin >> n;
  forn(i, n) cin >> a[i];
  vector<int> b(n - 1);
  forn(i, n - 1) b[i] = __gcd(a[i], a[i + 1]);
  int x, y, z;
  x = y = z = -1;

  // dbg(b);

  forn(i, n - 1) {
    if (b[i] > b[i + 1]) {
      x = i, y = i + 1, z = i + 2;
      break;
    }
  }

  // dbg(x);

  if (x == -1)
    cout << "YES\n";
  else if (f(x) || f(y) || f(z))
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
