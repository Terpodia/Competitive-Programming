#include <algorithm>
#include <iostream>
using namespace std;

#define INF (int)1e9

struct rock {
  int pos;
  char size;
};

const int MAXN = 107;
int N;
int D;
rock rocks[MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void solve() {
  bool flag = true;
  int actualPos = 0;
  int ans = -INF;
  for (int i = 0; i <= N; i++) {
    if (i == N) {
      ans = max(ans, D - actualPos);
      actualPos = D;
    }

    else if (rocks[i].size == 'B') {
      ans = max(ans, rocks[i].pos - actualPos);
      actualPos = rocks[i].pos;
    } else {
      if (flag) {
        flag = false;
        ans = max(ans, rocks[i].pos - actualPos);
        actualPos = rocks[i].pos;
        rocks[i].pos = -1;
      } else
        flag = true;
    }
  }

  for (int i = N - 1; i >= -1; i--) {
    if (i == -1) {
      ans = max(ans, actualPos - 0);
      actualPos = 0;
    } else if (rocks[i].size == 'B' || rocks[i].pos != -1) {
      ans = max(ans, actualPos - rocks[i].pos);
      actualPos = rocks[i].pos;
    }
  }

  cout << ans << "\n";
}

int main() {
  fastIO();

  int t;
  cin >> t;
  int c = 1;
  while (t--) {
    cin >> N >> D;

    for (int i = 0; i < N; i++) {
      char r;
      cin >> rocks[i].size >> r >> rocks[i].pos;
    }

    cout << "Case " << c << ": ";
    solve();
    c++;
  }

  return 0;
}
