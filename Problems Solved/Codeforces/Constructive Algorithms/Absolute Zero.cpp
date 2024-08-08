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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    ll a[n];
    forn(i, n) cin >> a[i];
    sort(a, a + n);
    bool can = true;
    forn(i, n) can &= (a[i] % 2 == a[0] % 2);
    if (!can) {
      cout << "-1\n";
      continue;
    }
    vector<ll> ans;
    ans.push_back(a[0]);
    dfor(i, 30) { ans.push_back(1 << i); }
    ans.push_back(1);

    cout << len(ans) << "\n";
    for (ll x : ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
