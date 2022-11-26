/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool solve(string& s, int a, int b, int c) {
  int cnt = 0;
  a = (a == 0) ? 1 : -1;
  b = (b == 0) ? 1 : -1;
  c = (c == 0) ? 1 : -1;

  forn(i, 0, sz(s)) {
    if (s[i] == 'A')
      cnt += a;
    else if (s[i] == 'B')
      cnt += b;
    else
      cnt += c;

    if (cnt < 0) return false;
  }

  return (cnt == 0);
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    string a;
    cin >> a;
    bool can = false;

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int z = 0; z < 2; z++) {
          can |= solve(a, i, j, z);
        }
      }
    }

    if (!can)
      cout << "NO\n";
    else
      cout << "YES\n";
  }

  return 0;
}
