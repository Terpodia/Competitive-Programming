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

void solve() {
  int a, b, n, m;
  cin >> a >> b >> n >> m;

  map<int, set<int>> c1, c2;

  forn(i, n) {
    int x, y;
    cin >> x >> y;
    c1[x].insert(y);
    c2[y].insert(x);
  }
  int ans1 = 0, ans2 = 0;

  pair<int, int> row, col;
  row = {1, a};
  col = {1, b};

  forn(i, m) {
    char d;
    int k;
    cin >> d >> k;
    int cnt = 0;

    if (d == 'U') {
      auto r = c1.lower_bound(row.fst + k);

      queue<int> del1;
      queue<pair<int, int>> del2;

      for (auto it = c1.begin(); it != r; it++) {
        del1.push(it->fst);
        for (int j : it->snd) {
          del2.push({j, it->fst});
        }
        cnt += len(it->snd);
      }

      while (!del1.empty()) {
        c1.erase(del1.front());
        del1.pop();
      }
      while (!del2.empty()) {
        pair<int, int> p = del2.front();
        del2.pop();
        c2[p.fst].erase(p.snd);
        if (c2[p.fst].empty()) c2.erase(p.fst);
      }

      row.fst += k;
    } else if (d == 'D') {
      auto r = c1.upper_bound(row.snd - k);

      queue<int> del1;
      queue<pair<int, int>> del2;

      for (auto it = r; it != c1.end(); it++) {
        del1.push(it->fst);
        for (int j : it->snd) {
          del2.push({j, it->fst});
        }
        cnt += len(it->snd);
      }

      while (!del1.empty()) {
        c1.erase(del1.front());
        del1.pop();
      }
      while (!del2.empty()) {
        pair<int, int> p = del2.front();
        del2.pop();
        c2[p.fst].erase(p.snd);
        if (c2[p.fst].empty()) c2.erase(p.fst);
      }

      row.snd -= k;
    } else if (d == 'L') {
      auto r = c2.lower_bound(col.fst + k);

      queue<int> del1;
      queue<pair<int, int>> del2;

      for (auto it = c2.begin(); it != r; it++) {
        del1.push(it->fst);
        for (int j : it->snd) {
          del2.push({j, it->fst});
        }
        cnt += len(it->snd);
      }

      while (!del1.empty()) {
        c2.erase(del1.front());
        del1.pop();
      }
      while (!del2.empty()) {
        pair<int, int> p = del2.front();
        del2.pop();
        c1[p.fst].erase(p.snd);
        if (c1[p.fst].empty()) c1.erase(p.fst);
      }

      col.fst += k;
    } else {
      auto r = c2.upper_bound(col.snd - k);

      queue<int> del1;
      queue<pair<int, int>> del2;

      for (auto it = r; it != c2.end(); it++) {
        del1.push(it->fst);
        for (int j : it->snd) {
          del2.push({j, it->fst});
        }
        cnt += len(it->snd);
      }

      while (!del1.empty()) {
        c2.erase(del1.front());
        del1.pop();
      }
      while (!del2.empty()) {
        pair<int, int> p = del2.front();
        del2.pop();
        c1[p.fst].erase(p.snd);
        if (c1[p.fst].empty()) c1.erase(p.fst);
      }
      col.snd -= k;
    }

    if (i % 2 == 0)
      ans1 += cnt;
    else
      ans2 += cnt;
  }
  cout << ans1 << " " << ans2 << "\n";
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
