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

void solve() {
  int n;
  cin >> n;
  int a[n], b[n];
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];
  map<int, int> pos;
  forn(i, n) pos[a[i]] = i;
  forn(i, n) {
    if (pos.find(b[i]) == pos.end()) {
      cout << "NO\n";
      return;
    }
  }
  ll cnt1 = 0, cnt2 = 0;
  ordered_set<int> s;
  forn(i, n) {
    cnt1 += (ll)len(s) - (ll)s.order_of_key(a[i]);
    s.insert(a[i]);
  }
  s.clear();
  forn(i, n) {
    cnt2 += (ll)len(s) - (ll)s.order_of_key(b[i]);
    s.insert(b[i]);
  }
  if (cnt1 % 2 == cnt2 % 2)
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
