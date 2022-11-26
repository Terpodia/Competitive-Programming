#include <iostream>
using namespace std;

const int MAXN = 50;

void fastIO() { cin.tie(0)->sync_with_stdio(false); }

int main() {
  fastIO();
  int t;
  cin >> t;

  const char c[2] = {'R', 'W'};

  while (t--) {
    int n, m;
    cin >> n >> m;
    char a[MAXN][MAXN];

    pair<int, int> pos = make_pair(-1, -1);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (pos != make_pair(-1, -1)) continue;
        if (a[i][j] != '.') pos = make_pair(i, j);
      }

    int x;

    if (pos == make_pair(-1, -1))
      x = 0;

    else {
      if (a[pos.first][pos.second] == 'R') {
        if (pos.first % 2 == 0)
          x = (pos.second % 2 == 0) ? 0 : 1;
        else
          x = (pos.second % 2 == 0) ? 1 : 0;
      } else {
        if (pos.first % 2 == 0)
          x = (pos.second % 2 == 0) ? 1 : 0;
        else {
          x = (pos.second % 2 == 0) ? 0 : 1;
        }
      }
    }

    bool can = true;

    for (int i = 0; i < n; i++) {
      int init = x;

      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.')
          a[i][j] = c[x];
        else if (a[i][j] != c[x]) {
          can = false;
          break;
        }

        x = 1 - x;
      }

      x = 1 - init;
    }

    if (can) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j];

        cout << "\n";
      }
    }

    else
      cout << "NO\n";
  }

  return 0;
}
