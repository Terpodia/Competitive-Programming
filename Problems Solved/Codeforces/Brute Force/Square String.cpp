#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    if (sz(s) % 2 != 0)
      puts("NO");
    else {
      string a, b;
      for (int i = 0; i < sz(s) / 2; i++) a.push_back(s[i]);
      for (int i = sz(s) / 2; i < sz(s); i++) b.push_back(s[i]);
      (a == b) ? puts("YES") : puts("NO");
    }
  }

  return 0;
}
