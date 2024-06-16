#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  string s[48];
  forn(i, 12) forn(j, 50) s[i].pb('A');
  fore(i, 12, 24) forn(j, 50) s[i].pb('B');
  fore(i, 24, 36) forn(j, 50) s[i].pb('C');
  fore(i, 36, 48) forn(j, 50) s[i].pb('D');

  a--, b--, c--, d--;

  for (int i = 0; i < 12; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (d == 0) break;
      s[i][j] = 'D';
      d--;
    }
  }
  for (int i = 12; i < 24; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (c == 0) break;
      s[i][j] = 'C';
      c--;
    }
  }
  for (int i = 24; i < 36; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (a == 0) break;
      s[i][j] = 'A';
      a--;
    }
  }
  for (int i = 36; i < 48; i += 2) {
    for (int j = 0; j < 50; j += 2) {
      if (b == 0) break;
      s[i][j] = 'B';
      b--;
    }
  }

  cout << 48 << " " << 50 << "\n";
  forn(i, 48) {
    forn(j, 50) cout << s[i][j];
    cout << "\n";
  }

  return 0;
}
