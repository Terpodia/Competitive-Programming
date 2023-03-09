#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    int p1, p2;
    for (int i = 0; i < n; i++) {
      if (p[i] == 1)
        p1 = i;
      else if (p[i] == n)
        p2 = i;
    }

    bool can = false, flag = true;
    int curr = p1;
    for (int i = 0; i < n; i++) {
      flag &= p[curr] == i + 1;
      curr = (curr + 1) % n;
    }
    can |= flag;

    flag = true;
    curr = p2;
    for (int i = n; i >= 1; i--) {
      flag &= p[curr] == i;
      curr = (curr + 1) % n;
    }
    can |= flag;

    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
