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

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  int a[n];
  forn(i, n) cin >> a[i];
  int b[m];
  forn(i, m) cin >> b[i];

  map<int, int> f;
  forn(i, n) f[a[i]] = i;

  vector<int> v(n, INF);

  set<int> pos[n];
  forn(i, m) { pos[f[b[i]]].insert(i); }
  forn(i, n) {
    if (len(pos[i]) == 0) continue;
    v[i] = *pos[i].begin();
  }
  ll sum = 0;
  forn(i, n - 1) sum += (ll)abs(v[i + 1] - v[i]);

  if (sum == abs(v[n - 1] - v[0]) && v[n - 1] >= v[0])
    cout << "YA\n";
  else
    cout << "TIDAK\n";

  while (q--) {
    int s, t;
    cin >> s >> t;
    s--;

    int j = f[b[s]];

    if (j > 0) sum -= (ll)abs(v[j] - v[j - 1]);
    if (j < n - 1) sum -= (ll)abs(v[j + 1] - v[j]);

    pos[j].erase(s);
    if (!len(pos[j]))
      v[j] = INF;
    else
      v[j] = *pos[j].begin();

    if (j > 0) sum += (ll)abs(v[j] - v[j - 1]);
    if (j < n - 1) sum += (ll)abs(v[j + 1] - v[j]);

    j = f[t];
    b[s] = t;
    pos[j].insert(s);

    if (j > 0) sum -= (ll)abs(v[j] - v[j - 1]);
    if (j < n - 1) sum -= (ll)abs(v[j + 1] - v[j]);

    v[j] = *pos[j].begin();

    if (j > 0) sum += (ll)abs(v[j] - v[j - 1]);
    if (j < n - 1) sum += (ll)abs(v[j + 1] - v[j]);

    if (sum == abs(v[n - 1] - v[0]) && v[n - 1] >= v[0])
      cout << "YA\n";
    else
      cout << "TIDAK\n";
  }
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
