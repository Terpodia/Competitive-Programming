/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
using namespace std;

#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void tc() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    forn(i, 0, n) cin >> a[i];
    int s = 0;

    forn(i, 0, n) if (a[i] == 1 || a[i] == 3) s++;
    cout << s << "\n";
  }
}

int main() {
  fastIO();
  tc();

  return 0;
}
