#include <algorithm>
#include <iostream>
using namespace std;

#define fst first
#define snd second

int n, m, i1, j1, i2, j2;
string dir;
pair<int, int> d;

int mvrow(int r) {
  int diff = d.fst * (r - i1);
  return (diff < 0) ? -1 : diff;
}

int mvcol(int c) {
  int diff = d.snd * (c - j1);
  return (diff < 0) ? -1 : diff;
}

int solve() {
  for (int cnt = 0; cnt <= 2 * n * m; cnt++) {
    if (mvrow(i2) == mvcol(j2) && mvrow(i2) != -1) return cnt;
    int r, c;
    r = (d.fst == 1) ? mvrow(n) : mvrow(1);
    c = (d.snd == 1) ? mvcol(m) : mvcol(1);
    i1 += d.fst * min(r, c), j1 += d.snd * min(r, c);
    if (r == c)
      d.fst *= -1, d.snd *= -1;
    else if (r < c)
      d.fst *= -1;
    else
      d.snd *= -1;
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> dir;
    if (dir == "DR")
      d = {1, 1};
    else if (dir == "DL")
      d = {1, -1};
    else if (dir == "UR")
      d = {-1, 1};
    else
      d = {-1, -1};
    cout << solve() << "\n";
  }
  return 0;
}
