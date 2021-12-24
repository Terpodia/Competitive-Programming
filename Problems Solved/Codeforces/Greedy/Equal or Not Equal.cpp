#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t; cin >> t;

  while (t--) {
    string s; cin >> s;
    int cnt=0;
    for (char c : s) if (c == 'N') cnt++;
    
    (cnt == 1) ? cout << "NO\n" : cout << "YES\n";
  }

  return 0;
}

