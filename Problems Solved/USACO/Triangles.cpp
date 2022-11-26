#include <algorithm>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

struct pos {
  int x, y;
};

const int MAXN = 100, INF = 1e9;
int N;
pos a[MAXN];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int solve(pos p1, pos p2, pos p3) {
  pos p[] = {p1, p2, p3};

  for (int i = 0; i < 3; i++) {
    pos b, c;
    b = c = {-INF, -INF};

    for (int j = 0; j < 3; j++) {
      if (i != j) {
        if (b.x == -INF)
          b = p[j];
        else
          c = p[j];
      }
    }

    if (p[i].x == b.x && p[i].y == c.y)
      return (abs(p[i].y - b.y)) * (abs(p[i].x - c.x));

    else if (p[i].y == b.y && p[i].x == c.x)
      return (abs(p[i].x - b.x)) * (abs(p[i].y - c.y));
  }

  return -1;
}

int main() {
  setIO("triangles");
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i].x >> a[i].y;

  int ans = 0;

  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      for (int z = j + 1; z < N; z++) {
        int area = solve(a[i], a[j], a[z]);
        if (area != -1) ans = max(ans, area);
      }

  cout << ans << "\n";

  return 0;
}
