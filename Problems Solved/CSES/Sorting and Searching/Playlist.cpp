#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int MAXN = 2e5;
int n, k[MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void solve() {
  map<int, int> mp;
  int ans = 0, l = 0;

  for (int i = 0; i < n; i++) {
    auto itr = mp.find(k[i]);

    if (itr != mp.end()) {
      int newl = itr->second + 1;

      for (int j = itr->second; j >= l; j--) mp.erase(k[j]);
      l = newl;
    }

    mp[k[i]] = i;
    ans = max(ans, (int)mp.size());
  }

  cout << ans << endl;
}

int main() {
  fastIO();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> k[i];

  solve();
  return 0;
}
