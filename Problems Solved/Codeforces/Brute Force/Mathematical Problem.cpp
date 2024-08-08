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

const ll INF = 1e18;

int n;
string s;

void solve() {
  if (n == 2) {
    cout << stoi(s) << "\n";
    return;
  }
  ll ans = INF;
  forn(k, n - 1) {
    vector<int> v;
    forn(i, k) v.push_back(s[i] - '0');
    v.push_back((s[k] - '0') * 10 + (s[k + 1] - '0'));
    fore(i, k + 2, n) v.push_back(s[i] - '0');

    for (int i : v) {
      if (i == 0) {
        cout << "0\n";
        return;
      }
    }

    ll lst = 0;

    ll res = 0;

    if (v[0] == 1 || v[1] == 1)
      res = v[0] * v[1], lst = v[0] * v[1];
    else
      res = v[0] + v[1], lst = v[0] + v[1];

    fore(i, 2, len(v)) {
      if (lst == 1 || v[i] == 1)
        res = lst * v[i], lst = lst * v[i];
      else
        res = lst + v[i], lst = lst + v[i];
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    solve();
  }
  return 0;
}
