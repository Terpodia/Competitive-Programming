/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
#include <string>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool check(string x) {
  int n = stoi(x);

  if (n == 1) return false;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;

    int cnt = 0;
    string ans;

    for (int i = 0; i < k; i++) {
      if (cnt != 0) break;

      string n(1, s[i]);
      if (!check(n)) {
        cnt = 1;
        ans.push_back(s[i]);
      }
    }

    for (int i = 0; i < k; i++) {
      if (cnt != 0) break;
      string n;
      n.push_back(s[i]);

      for (int j = i + 1; j < k; j++) {
        n.push_back(s[j]);
        if (!check(n)) {
          cnt = 2;
          ans = n;
          break;
        }

        n.pop_back();

        if (cnt != 0) break;
      }
    }

    cout << cnt << "\n";
    cout << ans << "\n";
  }

  return 0;
}
