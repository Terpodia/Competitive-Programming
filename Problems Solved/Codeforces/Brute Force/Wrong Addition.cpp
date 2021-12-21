#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int tc; cin >> tc;

  while (tc--) {
    string x, s;
    cin >> x >> s;
    
    string a;
    for (int i=0; i<100; i++) a.push_back('0');
    a += x;

    bool can = true;
    string b = "";

    int i = sz(s)-1, j = sz(a)-1;

    while (i > -1) {
      if (s[i] >= a[j]) {
        b.push_back((char)(((int)(s[i] - '0') - (int)(a[j] - '0')) + '0'));
        i--, j--;
      }

      else if (s[i] < a[j] && i > 0 && s[i-1] == '1') {
        string d; d.push_back('1'); d.push_back(s[i]);
        b.push_back((char)((stoi(d) - (int)(a[j] - '0')) + '0'));
        i-=2;
        j--;
      }

      else { can = false; break; }
    }

    if (i != -1 || j > sz(a) - sz(x) - 1) can = false;

    reverse(b.begin(), b.end());

    if (!can) cout << "-1\n";
    else {
      bool flag = false;
      for (char c : b) {
        if (c != '0') flag = true;
        if (flag) cout << c;
      }
      cout << "\n";
    }
  }

  return 0;
}

