// https://codeforces.com/gym/101142

#include <algorithm>
#include <iostream>
using namespace std;

#define f first
#define s second

typedef pair<int, int> ii;

const int MAXN = 1e5;

int n;
ii ratings[MAXN];

bool comp(ii& a, ii& b) { return a.f > b.f; }

void setIO(string s = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (!s.empty()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("codecoder");
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ratings[i].f >> ratings[i].s;

  ii cf[n], tc[n];
  for (int i = 0; i < n; i++)
    cf[i] = {ratings[i].f, i}, tc[i] = {ratings[i].s, i};

  sort(cf, cf + n, comp);
  sort(tc, tc + n, comp);
  int pos[n];
  for (int i = 0; i < n; i++) pos[tc[i].s] = i;

  int ans[n];
  for (int i = 0; i < n; i++) ans[i] = 0;

  int j = n - 1;

  while (j >= 0) {
    int k = j, lo = pos[cf[k].s];
    while (k > lo) {
      int w = lo;
      for (int i = w; i <= k; i++) lo = min(lo, pos[cf[i].s]);
      k = w;
    }
    for (int i = k; i <= j; i++) ans[cf[i].s] = j - k + n - j - 1;
    j = k - 1;
  }

  for (int i = 0; i < n; i++) cout << ans[i] << "\n";

  return 0;
}
