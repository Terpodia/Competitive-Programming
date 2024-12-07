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

struct pt {
  ll x, y;
  pt() {}
  pt(ll _x, ll _y) : x(_x), y(_y) {}
  ll norm2() { return *this * *this; }
  pt operator+(pt p) { return pt(x + p.x, y + p.y); }
  pt operator-(pt p) { return pt(x - p.x, y - p.y); }
  pt operator*(ll k) { return pt(x * k, y * k); }
  ll operator*(pt p) { return x * p.x + y * p.y; }
};

void solve() {
  int n;
  cin >> n;
  pt p[n];
  forn(i, n) cin >> p[i].x >> p[i].y;
  pt s, e;
  cin >> s.x >> s.y >> e.x >> e.y;
  pt d = e - s;

  bool can = true;

  ll t = d.norm2();

  forn(i, n) {
    ll t2 = (e - p[i]).norm2();
    if (t >= t2) can = false;
  }
  if (can)
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
