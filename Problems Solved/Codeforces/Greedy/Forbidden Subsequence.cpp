#include <cstring>
#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int TC;
  cin >> TC;

  while (TC--) {
    string s, t;
    cin >> s >> t;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    for (char c : s) cnt[c - 'a']++;

    string ans;

    if (t[0] == 'a' && t[1] == 'b' && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
      for (int j = 0; j < cnt[0]; j++) ans.push_back('a');

      for (int j = 0; j < cnt[2]; j++) ans.push_back('c');

      for (int j = 0; j < cnt[1]; j++) ans.push_back('b');

      for (int i = 3; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) ans.push_back((char)(i + 'a'));
      }
    } else {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) ans.push_back((char)(i + 'a'));
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
