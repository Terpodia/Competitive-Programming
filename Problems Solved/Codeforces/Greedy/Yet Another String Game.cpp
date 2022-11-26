#include <iostream>
using namespace std;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int main() {
  fastIO();

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int turn = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (turn == 0) {
        if (s[i] == 'a') {
          s[i] = 'b';
        } else
          s[i] = 'a';
      } else {
        if (s[i] == 'z') {
          s[i] = 'y';
        } else
          s[i] = 'z';
      }

      turn = 1 - turn;
    }

    cout << s << "\n";
  }

  return 0;
}
