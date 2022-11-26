#include <iostream>
using namespace std;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n], ans[n];

    for (int i = 0; i < n; i++) {
      a[i] = s[i] - '0';
      ans[i] = 0;
    }
    ans[0]++;
    a[0]++;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] == a[i]) {
        a[i]++;
        ans[i]++;
      } else if (a[i - 1] != a[i] + 1) {
        a[i]++;
        ans[i]++;
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << "\n";
  }

  return 0;
}
