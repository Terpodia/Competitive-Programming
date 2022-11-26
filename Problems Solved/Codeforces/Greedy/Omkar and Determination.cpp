#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  string a[n];
  FOR(i, 0, n) cin >> a[i];

  vector<int> vec;

  FOR(i, 1, n) FOR(j, 1, m) {
    if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X') vec.push_back(j - 1);
  }

  sort(vec.begin(), vec.end());

  int q;
  cin >> q;
  while (q--) {
    int x1, x2;
    cin >> x1 >> x2;
    x1--, x2--;
    auto it = lower_bound(vec.begin(), vec.end(), x1);

    if (it == vec.end() || *it >= x2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
