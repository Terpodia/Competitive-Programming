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
    int m;
    cin >> m;
    string t;
    cin >> t;

    vector<int> n, s, w, e;
    forn(i, m) {
      if (t[i] == 'N')
        n.push_back(i);
      else if (t[i] == 'S')
        s.push_back(i);
      else if (t[i] == 'E')
        e.push_back(i);
      else if (t[i] == 'W')
        w.push_back(i);
    }
    if ((len(n) + len(s)) % 2 == 1 || (len(e) + len(w)) % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    string ans = t;

    int i = 0;
    int cur = 0;
    while (i < len(n) || i < len(s)) {
      if (i < len(n)) {
        ans[n[i]] = (cur == 0) ? 'H' : 'R';
      }
      if (i < len(s)) {
        ans[s[i]] = (cur == 0) ? 'H' : 'R';
      }
      cur = 1 - cur;
      i++;
    }

    i = 0, cur = 1;
    while (i < len(w) || i < len(e)) {
      if (i < len(w)) {
        ans[w[i]] = (cur == 0) ? 'H' : 'R';
      }
      if (i < len(e)) {
        ans[e[i]] = (cur == 0) ? 'H' : 'R';
      }
      cur = 1 - cur;
      i++;
    }

    bool flag1 = false, flag2 = false;
    for (char c : ans)
      if (c == 'H') flag1 = true;
    for (char c : ans)
      if (c == 'R') flag2 = true;

    if (flag1 && flag2)
      cout << ans << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
