#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;

    for (char c : s) {
      if (c == 'R')
        cnt[0]++;
      else if (c == 'S')
        cnt[1]++;
      else
        cnt[2]++;
    }

    char x;
    if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2])
      x = 'P';
    else if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2])
      x = 'R';
    else
      x = 'S';

    for (int i = 0; i < sz(s); i++) cout << x;
    cout << "\n";
  }

  return 0;
}
