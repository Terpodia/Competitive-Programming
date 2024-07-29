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
  int n, m;
  cin >> n >> m;
  vector<int> v[m];

  vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);

  forn(i, m) {
    int k;
    cin >> k;
    forn(j, k) {
      int f;
      cin >> f;
      v[i].pb(f);
      cnt1[f]++;
      if (k == 1) cnt2[f]++;
    }
  }
  bool flag = true;
  fore(i, 1, n + 1) flag &= cnt1[i] <= (m + 1) / 2;
  if (flag) {
    cout << "YES\n";
    forn(i, m) cout << v[i][0] << " ";
    cout << "\n";
    return;
  }
  fore(i, 1, n + 1) {
    if (cnt1[i] > (m + 1) / 2 && cnt2[i] <= (m + 1) / 2) {
      vector<int> ans(m, 0);
      int cur = 0;

      forn(j, m) if (len(v[j]) == 1 && v[j][0] == i) { ans[j] = i, cur++; }
      forn(j, m) if (len(v[j]) > 1) {
        if (cur == (m + 1) / 2) break;
        bool check = false;
        for (int val : v[j]) {
          if (val == i) check = true;
        }
        if (check) {
          ans[j] = i;
          cur++;
        }
      }
      forn(j, m) if (ans[j] == 0) {
        if (v[j][0] == i)
          ans[j] = v[j][1];
        else
          ans[j] = v[j][0];
      }
      cout << "YES\n";
      for (int j : ans) cout << j << " ";
      cout << "\n";
      return;
    }
  }
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
