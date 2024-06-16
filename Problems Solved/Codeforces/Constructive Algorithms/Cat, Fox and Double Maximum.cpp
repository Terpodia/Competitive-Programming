#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)x.size()
#define pb push_back
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dbg(x) cerr << #x << "=" << x
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

typedef pair<int, int> pint;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int p[n];
    forn(i, n) cin >> p[i];
    bool flag = false;
    forn(i, n) if (p[i] == n) flag = (i % 2 == 1);

    vector<pint> v1, v2;
    forn(i, n) {
      if (i % 2 == 0)
        v1.pb({p[i], i});
      else
        v2.pb({p[i], i});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans[n];

    if (!flag) {
      int cur = n;
      for (auto [x, y] : v1) ans[y] = cur--;
      for (auto [x, y] : v2) ans[y] = cur--;
    } else {
      int cur = n;
      for (auto [x, y] : v2) ans[y] = cur--;
      for (auto [x, y] : v1) ans[y] = cur--;
    }
    forn(i, n) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
