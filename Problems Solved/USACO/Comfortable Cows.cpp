#include <iostream>
#include <vector>
using namespace std;

const int MAXM = 4000;

int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1}, N;
vector<vector<bool>> a(MAXM, vector<bool>(MAXM, false));

long long ans = 0;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int p(int x, int y) {
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int x2 = x + mx[i], y2 = y + my[i];
    if (a[x2][y2]) res++;
  }
  return res;
}

void floodfill(int x, int y) {
  int cnt = p(x, y);

  for (int i = 0; i < 4; i++) {
    int x2 = x + mx[i], y2 = y + my[i];

    if (!a[x2][y2] && cnt == 3) {
      ans++;
      a[x2][y2] = true;
      floodfill(x2, y2);
    } else if (a[x2][y2] && p(x2, y2) == 3) {
      for (int j = 0; j < 4; j++) {
        int x3 = x2 + mx[j], y3 = y2 + my[j];
        if (!a[x3][y3]) {
          ans++;
          a[x3][y3] = true;
          floodfill(x3, y3);
          break;
        }
      }
    }
  }
}

int main() {
  fastIO();
  cin >> N;

  while (N--) {
    int x, y;
    cin >> x >> y;
    if (a[x + 1500][y + 1500]) {
      ans--;
      cout << ans << "\n";
    } else {
      a[x + 1500][y + 1500] = true;
      floodfill(x + 1500, y + 1500);
      cout << ans << "\n";
    }
  }

  return 0;
}
