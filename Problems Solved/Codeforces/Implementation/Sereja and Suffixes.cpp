#include <iostream>
#include <map>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[a[i]]++;
  int ans[n];
  ans[0] = sz(mp);

  for (int i = 1; i < n; i++) {
    mp[a[i - 1]]--;
    if (mp[a[i - 1]] == 0) mp.erase(a[i - 1]);
    ans[i] = sz(mp);
  }

  while (m--) {
    int l;
    cin >> l;
    cout << ans[l - 1] << "\n";
  }

  return 0;
}
