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

const int rm[] = {1, -1, 0, 0}, cm[] = {0, 0, 1, -1};

int n, m;

string s[2001];

void solve() {
  string ans[n];
  forn(i, n) ans[i] = s[i];

  queue<pair<int, int>> q;

  forn(i, n) forn(j, m) if (s[i][j] == '.') {
    int cnt = 0;
    forn(_, 4) {
      int r = i + rm[_], c = j + cm[_];
      if (r < 0 || c < 0 || r >= n || c >= m) continue;
      if (s[r][c] == '.') cnt++;
    }
    if (cnt == 1) q.push(make_pair(i, j));
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    forn(_, 4) {
      int r = i + rm[_], c = j + cm[_];
      if (r < 0 || c < 0 || r >= n || c >= m) continue;
      if (s[r][c] == '.') {
        if (_ == 0)
          s[i][j] = '^', s[r][c] = 'v';
        else if (_ == 1)
          s[i][j] = 'v', s[r][c] = '^';
        else if (_ == 2)
          s[i][j] = '<', s[r][c] = '>';
        else
          s[i][j] = '>', s[r][c] = '<';

        forn(__, 4) {
          int rr = r + rm[__], cc = c + cm[__];
          if (rr < 0 || cc < 0 || rr >= n || cc >= m || s[rr][cc] != '.')
            continue;
          int cnt = 0;
          forn(___, 4) {
            int rrr = rr + rm[___], ccc = cc + cm[___];
            if (rrr < 0 || ccc < 0 || rrr >= n || ccc >= m ||
                s[rrr][ccc] != '.')
              continue;
            cnt++;
          }
          if (cnt == 1) q.push(make_pair(rr, cc));
        }
      }
    }
  }

  bool can = true;
  forn(i, n) forn(j, m) if (s[i][j] == '.') can = false;

  if (!can)
    cout << "Not unique\n";
  else {
    forn(i, n) {
      forn(j, m) cout << s[i][j];
      cout << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  forn(i, n) cin >> s[i];
  solve();
  return 0;
}
