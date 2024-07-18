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

void query(vector<int> &a, vector<int> &b) {
  cout << len(a) << " " << len(b) << " ";
  forn(i, len(a)) cout << a[i] << " ";
  forn(i, len(b) - 1) cout << b[i] << " ";
  cout << b.back() << endl;

  a.clear();
  b.clear();
}

void solve() {
  int n;
  cin >> n;
  vector<int> a = {1};
  vector<int> b;
  fore(i, 1, n) b.push_back(i + 1);
  query(a, b);

  int d;
  cin >> d;
  if (d == -1) return;

  if (n == 2) {
    cout << "-1 " << d << endl;
    return;
  }

  int l = 1, r = n - 1, cnt = 0;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    a.push_back(1);
    fore(i, mid, n) b.push_back(i + 1);
    query(a, b);
    int d1;
    cin >> d1;
    if (d1 == -1) return;
    if (d1 == d)
      l = mid;
    else
      r = mid - 1;
    cnt++;
  }
  a.push_back(l + 1);
  forn(i, n) if (i != l) b.push_back(i + 1);
  query(a, b);
  int ans;
  cin >> ans;
  if (ans == -1) return;
  cout << "-1 " << ans << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
