#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<int> v1, v2;
  for (int i = 0; i < n; i++) v1.push_back(a[i] - b[i]);
  for (int i = 0; i < n; i++) v2.push_back(b[i] - a[i]);

  int index1[n], index2[n];

  sort(all(v1));
  sort(all(v2));
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= b[i]) {
      auto it = upper_bound(all(v1), b[i] - a[i]);
      ll j = (ll)distance(v1.begin(), it);
      ans += (ll)n - j;
    } else {
      auto it = lower_bound(all(v2), a[i] - b[i]);
      ll j = (ll)distance(v2.begin(), it);
      j--;
      ans += (ll)j;
    }
  }
  ans /= (ll)2;
  cout << ans << "\n";
  return 0;
}
