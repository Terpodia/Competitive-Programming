#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define f first
#define s second
#define INF (int)1e9

typedef pair<int, int> ii;

const int MAXN = 10000;
int N;
ii a[MAXN];

void solve() {
  vector<int> t[MAXN + 7];
  priority_queue<int> Q;
  int lastTime = -INF;
  for (int i = 0; i < N; i++) {
    t[a[i].s].push_back(a[i].f);
    lastTime = a[i].s > lastTime ? a[i].s : lastTime;
  }

  int ans = 0;

  for (int i = lastTime; i >= 0; i--) {
    if (!Q.empty()) {
      ans += Q.top();
      Q.pop();
    }
    for (int j = 0; j < (int)t[i].size(); j++) Q.push(t[i][j]);
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d", &a[i].f, &a[i].s);

  solve();

  return 0;
}
