#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    string s; cin >> s;
    int cnt=0;

    int i=0;

    while (i < sz(s)) {
      if (s[i] == '0') {
        cnt++;
        while (i < sz(s) && s[i] == '0') i++;
      }
      else i++;
    }

    if (cnt == 0) cout << 0 << "\n";
    else if (cnt == 1) cout << 1 << "\n";
    else cout << 2 << "\n";
  }

  return 0;
}

