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
  int n, x;
  cin >> n >> x;
  int a[n];
  forn(i, n) cin >> a[i];

  int ans = 1;
  unordered_set<int> cur;
  cur.insert(1);
  if (x % a[0] == 0) cur.insert(a[0]);

  fore(i, 1, n) {
    if (x % a[i] != 0) continue;
    queue<int> add;
    bool check = false;
    for (int d : cur) {
      add.push(d * a[i]);
      if (d * a[i] == x) {
        check = true;
        break;
      }
    }
    if (check) {
      ans++;
      cur.clear();
      cur.insert(1);
      cur.insert(a[i]);
    } else {
      while (!add.empty()) {
        if (x % add.front() == 0) cur.insert(add.front());
        add.pop();
      }
    }
  }
  cout << ans << "\n";
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
