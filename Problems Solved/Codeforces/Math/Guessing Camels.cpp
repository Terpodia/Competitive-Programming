#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

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

ll calc(vector<int> a, vector<int> b) {
  int n = len(a);
  map<int, int> f;
  forn(i, n) f[a[i]] = i;
  forn(i, n) b[i] = f[b[i]];
  ll ret = 0;
  ordered_set<int> cur;
  forn(i, n) {
    cur.insert(b[i]);
    ll cnt = (ll)cur.order_of_key(b[i]);
    ret += (ll)len(cur) - cnt - 1LL;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];
  forn(i, n) cin >> c[i];
  calc(a, b);
  ll cnt = calc(a, b) + calc(a, c) + calc(b, c);

  cnt /= 2;
  ll ans = ((ll)n * (ll)(n - 1LL)) / 2LL;
  ans -= cnt;
  cout << ans << "\n";
  return 0;
}
