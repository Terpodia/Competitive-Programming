#include <iostream>
using namespace std;

int N, K;
string s;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void solve() {
  int cnt = 1;
  bool flag = false;

  for (int i = 1; i < N; i++) {
    if (s[i] == s[i - 1])
      cnt++;
    else
      cnt = 1;
    if (cnt >= K) flag = true;
  }

  if (!flag)
    cout << "-1\n";
  else {
    int ans = 0;
    cnt = 1;
    for (int i = 0; i < N; i++) {
      if (cnt == K) {
        cnt = 1;
        ans++;
      } else if (i != N - 1 && s[i] == s[i + 1])
        cnt++;

      else if (i == N - 1)
        ans++;

      else if (s[i] != s[i + 1]) {
        ans++;
        cnt = 1;
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> N >> K;
    cin >> s;

    solve();
  }

  return 0;
}
