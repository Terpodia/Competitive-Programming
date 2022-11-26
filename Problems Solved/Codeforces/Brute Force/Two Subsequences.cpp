#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int j = 0;
    for (int i = 1; i < n; i++) {
      if (s[j] > s[i]) j = i;
    }
    cout << s[j] << " ";
    for (int i = 0; i < n; i++)
      if (i != j) cout << s[i];
    cout << "\n";
  }

  return 0;
}
