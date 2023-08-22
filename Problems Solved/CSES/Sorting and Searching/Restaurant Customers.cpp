#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct customer {
  int l, r, id;
};

const int MAXN = 2 * 1e5;
int n;
customer a[MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void solve() {
  pair<int, int> b[2 * n];
  for (int i = 0; i < n; i++) {
    b[i].first = a[i].l;
    b[i].second = a[i].id;
  }

  for (int i = n; i < 2 * n; i++) {
    b[i].first = a[i - n].r;
    b[i].second = a[i - n].id;
  }

  sort(b, b + 2 * n);
  vector<bool> check(n, false);

  int ans = 1;
  int cnt = 0;

  for (int i = 0; i < 2 * n; i++) {
    if (!check[b[i].second]) {
      cnt++;
      check[b[i].second] = true;
    } else {
      cnt--;
      check[b[i].second] = false;
    }
    ans = max(cnt, ans);
  }
  cout << ans << "\n";
}

int main() {
  fastIO();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].l >> a[i].r;
    a[i].id = i;
  }

  solve();

  return 0;
}
