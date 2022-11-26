#include <fstream>
using namespace std;

const int MAXM = 1007;
int N, K, a[MAXM][MAXM];

int main(void) {
  ifstream fin("paintbarn.in");
  ofstream fout("paintbarn.out");

  int ans = 0;
  fin >> N >> K;

  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    fin >> x1 >> y1 >> x2 >> y2;

    a[x1 + 1][y1 + 1]++;
    a[x2 + 1][y2 + 1]++;
    a[x2 + 1][y1 + 1]--;
    a[x1 + 1][y2 + 1]--;
  }

  for (int i = 1; i < MAXM; i++) {
    for (int j = 1; j < MAXM; j++) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      if (a[i][j] == K) ans++;
    }
  }

  fout << ans << "\n";

  return 0;
}
