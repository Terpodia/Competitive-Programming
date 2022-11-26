#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  string s;
  cin >> s;
  int a[26];
  memset(a, 0, sizeof(a));

  set<char> check;

  for (char c : s) {
    check.insert(c);
    a[c - 'a']++;
  }

  sort(a, a + 26);
  int ans = 0, m = sz(check);

  for (int i = 0; i < 26; i++) {
    if (m <= 2) break;
    if (a[i] > 0) {
      ans += a[i];
      m--;
    }
  }

  cout << ans << "\n";

  return 0;
}
