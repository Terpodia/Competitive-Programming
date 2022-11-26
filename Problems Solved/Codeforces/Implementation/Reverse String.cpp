#include <iostream>
using namespace std;

string s, t;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool f(int i, int j) {
  for (; i >= 0; i--) {
    if (j == (int)t.size()) break;
    if (s[i] != t[j]) return false;
    j++;
  }

  return j == (int)t.size();
}

bool solve(int i) {
  int j = 0;
  bool ret = false;

  for (; i < (int)s.size(); i++) {
    if (j == (int)t.size()) break;
    if (s[i] != t[j]) break;
    j++;

    ret |= f(i - 1, j);
  }

  ret |= j == (int)t.size();
  return ret;
}

int main() {
  fastIO();
  int q;
  cin >> q;

  while (q--) {
    cin >> s >> t;
    bool can = false;

    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != t[0]) continue;
      can |= solve(i);
    }

    (can) ? puts("YES") : puts("NO");
  }

  return 0;
}
