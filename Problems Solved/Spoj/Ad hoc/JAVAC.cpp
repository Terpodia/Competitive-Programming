#include <cctype>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  while (cin >> s) {
    bool has_underscore = false, has_capital_letter = false;
    bool has_adjacent_underscore = false;

    for (int i = 0; i < sz(s); i++) {
      if (s[i] == '_') {
        has_underscore = true;
        if (i < sz(s) - 1 && s[i + 1] == s[i]) has_adjacent_underscore = true;
      }

      else if (s[i] == toupper(s[i]))
        has_capital_letter = true;
    }

    if ((has_underscore && has_capital_letter) || (has_adjacent_underscore))
      cout << "Error!\n";

    else if (s[0] == '_' || s[0] == toupper(s[0]) || s[sz(s) - 1] == '_')
      cout << "Error!\n";

    else if (has_underscore) {
      string ans;
      int i = 0;
      while (i < sz(s)) {
        if (s[i] != '_')
          ans.push_back(s[i++]);
        else {
          ans.push_back(toupper(s[i + 1]));
          i += 2;
        }
      }
      cout << ans << "\n";
    }

    else {
      string ans;
      for (int i = 0; i < sz(s); i++) {
        if (s[i] != toupper(s[i]))
          ans.push_back(s[i]);
        else {
          ans.push_back('_');
          ans.push_back(tolower(s[i]));
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}

