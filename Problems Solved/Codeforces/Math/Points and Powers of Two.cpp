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

const ll INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> x(n);
  forn(i, n) cin >> x[i];

  map<ll, ll> mapa;
  forn(i, n) mapa[x[i]]++;

  vector<ll> ans;
  ans.push_back(x[0]);

  pair<ll, ll> pareja;
  pareja = {-1, -1};

  bool flag = false;

  forn(i, n) {
    if (len(ans) >= 3) break;
    forn(b, 31) {
      if (len(ans) >= 3) break;

      ll p = (1 << b);
      int cnt = 0;
      if (abs(x[i] + p) <= INF) {
        if (mapa.find(x[i] + p) != mapa.end()) {
          cnt++;
          pareja = {x[i], x[i] + p};
          flag = true;
        }
      }
      if (abs(x[i] - p) <= INF) {
        if (mapa.find(x[i] - p) != mapa.end()) {
          cnt++;
          pareja = {x[i], x[i] - p};
          flag = true;
        }
      }

      if (cnt == 2) {
        ans.clear();
        ans.push_back(x[i]);
        ans.push_back(x[i] + p);
        ans.push_back(x[i] - p);
      }
    }
  }

  if (len(ans) < 3 && flag) {
    cout << "2\n";
    cout << pareja.fst << " " << pareja.snd << "\n";
    return 0;
  }

  cout << len(ans) << "\n";
  forn(i, len(ans)) { cout << ans[i] << " "; }
  cout << "\n";
  return 0;
}
