#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
      s.push_back('(');
    }
    for (int i = n; i < n * 2; i++) {
      s.push_back(')');
    }

    int l = 0, r = n * 2 - 1, m = 0;

    while (r > l) {
      for (int i = l; i <= r; i++)
        cout << s[i];
      for (int i = 0; i < m; i++)
        cout << "()";

      cout << "\n";
      m++, r--, l++;
    }
  }

  return 0;
}