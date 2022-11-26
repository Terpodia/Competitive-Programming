#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 1e9;
int n;
vector<int> a;

int solve(int i, int j) {
  int ret = 0;

  vector<int> v;
  for (int l = 0; l < n * 2; l++)
    if (l != i && l != j) v.push_back(a[l]);

  for (int l = 0; l < (int)v.size(); l += 2) ret += v[l + 1] - v[l];

  return ret;
}

int main() {
  scanf("%d", &n);
  a.resize(n * 2);

  for (int i = 0; i < n * 2; i++) scanf("%d", &a[i]);

  sort(a.begin(), a.end());

  int ans = INF;

  for (int i = 0; i < n * 2; i++) {
    for (int j = i + 1; j < n * 2; j++) {
      ans = min(ans, solve(i, j));
    }
  }

  printf("%d\n", ans);

  return 0;
}
