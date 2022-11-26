#include <iostream>
using namespace std;

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') cnt++;

    if (cnt == 1)
      cout << "BOB\n";
    else if (n % 2 != 0 && s[n / 2] == '0')
      cout << "ALICE\n";
    else
      cout << "BOB\n";
  }

  return 0;
}
