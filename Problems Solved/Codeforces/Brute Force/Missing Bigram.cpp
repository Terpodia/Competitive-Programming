#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;

  while (t--) {
    int n; cin >> n;
    string a[n-2];
    for (int i=0; i<n-2; i++) cin >> a[i];

    bool flag = false;
    string ans = a[0];

    for (int i=1; i<n-2; i++) {
      if (a[i][0] == a[i-1][1]) ans.push_back(a[i][1]);
      else { ans.push_back(a[i][0]); ans.push_back(a[i][1]); flag = true; }
    }

    if (!flag) { flag = true; ans.push_back('a'); }
    cout << ans << "\n";
  }

  return 0;
}

