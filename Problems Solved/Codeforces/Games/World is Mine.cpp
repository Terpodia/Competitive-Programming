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

const int MAXN = 5050;

vector<int> b;
map<int, int> m;
int dp[MAXN][MAXN];

int f(int i, int j) {
  if (i >= len(b)) return 0;
  int &ret = dp[i][j];
  if (ret != -1) return ret;

  ret = 1 + f(i + 1, j + 1);
  if (m[b[i]] <= j) ret = min(ret, f(i + 1, j - m[b[i]]));
  return ret;
}

void solve() {
  int n;
  cin >> n;
  int a[n];
  forn(i, n) cin >> a[i];

  b.clear();
  m.clear();
  forn(i, n + 10) forn(j, n + 10) dp[i][j] = -1;

  forn(i, n) m[a[i]]++;
  for (auto &[x, y] : m) b.push_back(x);

  cout << f(0, 0) << "\n";
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
