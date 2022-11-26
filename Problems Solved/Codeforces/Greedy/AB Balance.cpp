#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cntab = 0, cntba = 0;

    int n = (int)s.size();

    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        cntab++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        cntba++;
    }

    if (cntab > cntba)
      s[n - 1] = 'a';
    else if (cntba > cntab)
      s[n - 1] = 'b';
    cout << s << "\n";
  }

  return 0;
}
