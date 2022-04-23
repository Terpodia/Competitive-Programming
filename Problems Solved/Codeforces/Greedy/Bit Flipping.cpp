#include <cstring>
#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, cnt;
    string s;
    cin >> n >> k >> s;
    cnt = k;
    int op[n];
    memset(op, 0, sizeof(op));

    for (int i = 0; i < n - 1; i++) {
      if (cnt == 0) break;
      if (s[i] == '1' && k % 2 == 0) continue;
      if (s[i] == '0' && k % 2 == 1) continue;
      op[i]++;
      cnt--;
    }
    op[n - 1] += cnt;

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ((k - op[i]) % 2 == 0) ? cout << "1" : cout << "0";
      } else {
        ((k - op[i]) % 2 == 1) ? cout << "1" : cout << "0";
      }
    }
    cout << "\n";
    for (int i = 0; i < n; i++) cout << op[i] << " \n"[i == n - 1];
  }
  return 0;
}

