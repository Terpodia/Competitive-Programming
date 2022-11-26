#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int MAXN = 5e5;

int n;
ll a[MAXN];

ll solve() {
  ll ret = 0;
  int adj[n][2];
  memset(adj, -1, sizeof(adj));

  for (int i = 1; i < n - 1; i++) adj[i][0] = i - 1, adj[i][1] = i + 1;

  queue<int> q;

  for (int i = 1; i < n - 1; i++)
    if (a[adj[i][0]] >= a[i] && a[adj[i][1]] >= a[i]) q.push(i);

  while (!q.empty()) {
    int i = q.front();
    q.pop();
    if (i == -1 || adj[i][0] == -1 || adj[i][1] == -1) continue;
    ret += min(a[adj[i][0]], a[adj[i][1]]);
    if (adj[i][0] > 0) adj[adj[i][0]][1] = adj[i][1];
    if (adj[i][1] < n - 1) adj[adj[i][1]][0] = adj[i][0];

    if (adj[i][0] > 0 && a[adj[adj[i][0]][0]] >= a[adj[i][0]] &&
        a[adj[adj[i][0]][1]] >= a[adj[i][0]])
      q.push(adj[i][0]);

    if (adj[i][1] < n - 1 && a[adj[adj[i][1]][0]] >= a[adj[i][1]] &&
        a[adj[adj[i][1]][1]] >= a[adj[i][1]])
      q.push(adj[i][1]);

    adj[i][0] = adj[i][1] = -1;
  }

  ll hi = 0;
  int curr = -1;

  for (int i = 0; i < n; i++) {
    if (adj[i][0] != -1 && adj[i][1] != -1) {
      if (hi < min(a[adj[i][0]], a[adj[i][1]])) {
        hi = min(a[adj[i][0]], a[adj[i][1]]);
        curr = i;
      }
    }
  }

  if (curr == -1) return ret;

  while (true) {
    ret += min(a[adj[curr][0]], a[adj[curr][1]]);

    if (adj[curr][0] > 0) adj[adj[curr][0]][1] = adj[curr][1];
    if (adj[curr][1] < n - 1) adj[adj[curr][1]][0] = adj[curr][0];

    if (adj[curr][0] == 0 && adj[curr][1] == n - 1) break;

    if (adj[curr][0] == 0)
      curr = adj[curr][1];
    else if (adj[curr][1] == n - 1)
      curr = adj[curr][0];
    else {
      if (min(a[adj[adj[curr][0]][0]], a[adj[adj[curr][0]][1]]) >=
          min(a[adj[adj[curr][1]][0]], a[adj[adj[curr][1]][1]]))
        curr = adj[curr][0];
      else
        curr = adj[curr][1];
    }
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  printf("%lld\n", solve());

  return 0;
}
