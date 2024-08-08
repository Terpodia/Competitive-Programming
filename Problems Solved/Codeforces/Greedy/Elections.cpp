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

void solve() {
  int n;
  ll c;
  cin >> n >> c;
  ll a[n];
  forn(i, n) cin >> a[i];
  if (n == 1) {
    cout << "0\n";
    return;
  }
  ll suff[n + 1], pref[n + 1], sum[n + 1];
  suff[n] = -INF;
  dfor(i, n) { suff[i] = max(suff[i + 1], a[i]); }
  pref[0] = -INF;
  fore(i, 1, n + 1) pref[i] = max(pref[i - 1], a[i - 1]);

  sum[0] = 0;
  fore(i, 1, n + 1) { sum[i] = sum[i - 1] + a[i - 1]; }

  vector<int> ans;
  if (a[0] + c < suff[1])
    ans.push_back(1);
  else
    ans.push_back(0);
  fore(i, 1, n - 1) {
    if (a[i] < suff[i + 1]) {
      if (sum[i + 1] + c < suff[i + 1])
        ans.push_back(i + 1);
      else
        ans.push_back(i);
    } else {
      if (a[i] <= a[0] + c || a[i] <= pref[i])
        ans.push_back(i);
      else
        ans.push_back(0);
    }
  }
  if (a[n - 1] > a[0] + c && a[n - 1] > pref[n - 1])
    ans.push_back(0);
  else
    ans.push_back(n - 1);

  for (int i : ans) cout << i << " ";
  cout << "\n";
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
