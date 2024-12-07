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

struct Project {
  int l, r;
  ll c;
  bool operator<(const Project &p) const {
    if (l != p.l) return l < p.l;
    if (r != p.r) return r < p.r;
    return c < p.c;
  }
};

const int MAXN = 2e5 + 10;

ll dp[MAXN];

int n;
Project a[MAXN];

ll solve(int i) {
  if (i == n) return 0;
  ll &ret = dp[i];
  if (ret != -1) return ret;
  ret = solve(i + 1);
  int j = lower_bound(a, a + n, (Project){a[i].r + 1, -1, -1}) - a;
  ret = max(ret, a[i].c + solve(j));
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) { cin >> a[i].l >> a[i].r >> a[i].c; }
  sort(a, a + n);
  memset(dp, -1, sizeof(dp));
  cout << solve(0) << "\n";
  return 0;
}
