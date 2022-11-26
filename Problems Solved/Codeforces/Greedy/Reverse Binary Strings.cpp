#include <algorithm>
#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int a1 = 0, a2 = 0;

    for (int i = 0; i < n - 1; i++)
      if (s[i] == '1' && s[i + 1] == '1') a1++;

    for (int i = 0; i < n - 1; i++)
      if (s[i] == '0' && s[i + 1] == '0') a2++;

    cout << max(a1, a2) << "\n";
  }

  return 0;
}
