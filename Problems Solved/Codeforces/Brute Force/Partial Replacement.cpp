#include <iostream>
using namespace std;

int n, k;
string s;

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void solve() {
  int ans = 0, pos = -1, aux;

  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      pos = i;
      s[i] = 'x';
      ans++;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '*') {
      s[i] = 'x';
      ans++;
      break;
    }
  }

  if (ans == 1) {
    cout << ans << "\n";
    return;
  }

  aux = pos;

  for (int i = pos + 1; i < n; i++) {
    if (i - pos > k) {
      ans++;
      pos = aux;
    }
    if (s[i] == '*') aux = i;
    if (s[i] == 'x') break;
  }

  cout << ans << "\n";
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> k;
    cin >> s;
    solve();
  }

  return 0;
}
