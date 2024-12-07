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
  cerr << "\n---------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.fst $ p.snd << ')';
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

const int MAX = 1e6;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int k, l;
    cin >> k >> l;
    if (l >= 2000)
      cout << "-1\n";
    else {
      vector<int> ans;
      ans.pb(-1);
      ans.pb(1);
      int sum = 0, n = 1;
      while (k - sum + n + 1 > MAX) {
        ans.pb(MAX);
        n++, sum += MAX;
      }
      int x = k - sum + n + 1;
      ans.pb(x);

      while (len(ans) < l) ans.pb(1);

      cout << len(ans) << "\n";

      for (int i : ans) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}
