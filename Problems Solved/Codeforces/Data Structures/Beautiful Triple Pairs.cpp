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
    int a[n];
    forn(i, n) cin >> a[i];
    map<pair<int, int>, vector<int>> cnt[3];

    forn(i, n - 2) {
      pair<int, int> x = {a[i], a[i + 1]};
      pair<int, int> y = {a[i], a[i + 2]};
      pair<int, int> z = {a[i + 1], a[i + 2]};
      cnt[0][x].push_back(a[i + 2]);
      cnt[1][y].push_back(a[i + 1]);
      cnt[2][z].push_back(a[i]);
    }
    forn(i, 3) {
      for (auto &[x, y] : cnt[i]) {
        sort(all(y));
      }
    }

    ll ans = 0;
    forn(i, n - 2) {
      pair<int, int> x = {a[i], a[i + 1]};
      pair<int, int> y = {a[i], a[i + 2]};
      pair<int, int> z = {a[i + 1], a[i + 2]};

      ans += (ll)len(cnt[0][x]) -
             (ll)distance(cnt[0][x].begin(),
                          upper_bound(all(cnt[0][x]), a[i + 2]));
      ans += (ll)distance(cnt[0][x].begin(),
                          lower_bound(all(cnt[0][x]), a[i + 2]));

      ans += (ll)len(cnt[1][y]) -
             (ll)distance(cnt[1][y].begin(),
                          upper_bound(all(cnt[1][y]), a[i + 1]));
      ans += (ll)distance(cnt[1][y].begin(),
                          lower_bound(all(cnt[1][y]), a[i + 1]));

      ans += (ll)len(cnt[2][z]) -
             (ll)distance(cnt[2][z].begin(), upper_bound(all(cnt[2][z]), a[i]));
      ans += (ll)distance(cnt[2][z].begin(), lower_bound(all(cnt[2][z]), a[i]));
    }

    cout << ans / 2LL << "\n";
  }
  return 0;
}
