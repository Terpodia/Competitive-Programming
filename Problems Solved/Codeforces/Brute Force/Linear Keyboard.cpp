#include <cstring>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    string k, s;
    cin >> k >> s;

    int a[26];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < sz(k); i++) {
      a[k[i] - 'a'] = i + 1;
    }

    int ans = 0;
    for (int i = 1; i < sz(s); i++) {
      ans += abs(a[s[i] - 'a'] - a[s[i - 1] - 'a']);
    }
    cout << ans << "\n";
  }

  return 0;
}
