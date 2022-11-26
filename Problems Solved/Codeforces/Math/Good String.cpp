#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9;

string s;
vector<string> a;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int solve(string b) {
  int j = 0, ret = 0;

  for (int i = 0; i < sz(s); i++) {
    if (s[i] != b[j])
      ret++;
    else
      j = 1 - j;
  }

  if (b[0] != b[1] && j == 1) ret++;

  return ret;
}

int main() {
  fastIO();

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      string b;
      b.push_back((char)(i + '0'));
      b.push_back((char)(j + '0'));
      a.push_back(b);
    }
  }

  int t;
  cin >> t;

  while (t--) {
    cin >> s;
    int ans = INF;

    for (string b : a) {
      ans = min(ans, solve(b));
    }

    cout << ans << "\n";
  }

  return 0;
}
