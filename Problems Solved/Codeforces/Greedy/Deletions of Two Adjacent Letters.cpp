#include <cstring>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    bool c[26];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < sz(s); i += 2) c[s[i] - 'a'] = true;
    char x;
    cin >> x;
    (c[x - 'a']) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
