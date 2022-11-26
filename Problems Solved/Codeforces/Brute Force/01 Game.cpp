#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

string s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool f() {
  bool ret = false;
  int l, r;
  for (int i = 0; i < sz(s) - 1; i++) {
    if (s[i + 1] != s[i]) {
      ret = true;
      l = i, r = i + 2;
      break;
    }
  }

  if (ret) s.erase(s.begin() + l, s.begin() + r);

  return ret;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    cin >> s;

    bool can = true;
    bool turn = false;

    while (can) {
      can = f();
      turn = !turn;
    }

    turn = !turn;

    (turn) ? puts("DA") : puts("NET");
  }

  return 0;
}
