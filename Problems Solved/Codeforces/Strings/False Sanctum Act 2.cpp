#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

// MACROS
#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
// FOR
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
// DEBUG
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

vector<int> pref(string &s) {
  vector<int> res(len(s) + 1, -1);
  int j = -1;
  forn(i, len(s)) {
    while (j > -1 && s[i] != s[j]) j = res[j];
    res[i + 1] = ++j;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<int> p = pref(s);
  vector<int> dp(n + 1, 0), r(n + 1, 0);

  fore(i, 1, n + 1) {
    if (r[dp[p[i]]] >= i - p[i])
      dp[i] = dp[p[i]];
    else
      dp[i] = i;
    r[dp[i]] = i;
  }
  cout << dp[n] << "\n";
  return 0;
}
