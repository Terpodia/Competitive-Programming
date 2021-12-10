#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string s, t;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int tc; cin >> tc;

  while (tc--) {
    cin >> s >> t;
    bool ok[26]; memset(ok, false, sizeof(ok));
    for (char c : s) ok[c-'a'] = true;
    
    bool can=true;
    for (char c : t) can &= (ok[c-'a']);

    if (!can) cout << "-1\n";
    else {
      vector<int> v[26];
      for (int i=0; i<(int)s.size(); i++)
        v[s[i]-'a'].push_back(i);

      int ans=0, i=0;
      pair<int,int> p = {t[0] - 'a' , -1};

      while (i < (int)t.size()) {
        auto it = upper_bound(v[p.first].begin(), v[p.first].end(), p.second);

        if (it == v[p.first].end()) ans++, p.second = -1;
        else {
          i++, p.second = *it; 
          if (i >= (int)t.size()) ans++;
          else p.first = t[i] - 'a';
        }
      }

      cout << ans << "\n";
    }
  }

  return 0;
}

