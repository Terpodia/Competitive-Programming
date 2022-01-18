#include <iostream>
#include <vector>
using namespace std;

void ask(int i) { cout << "? " << i << endl; }

int n;

void solve() {
  vector<bool> v(n + 1, false);
  int a[n + 1];
  for (int i = 1; i < n + 1; i++) {
    if (v[i]) continue;
    ask(i);
    int s, prev, nxt;
    cin >> s;
    prev = s;
    while (true) {
      ask(i);
      cin >> nxt;
      a[nxt] = prev;
      prev = nxt;
      v[nxt] = true;
      if (nxt == s) break;
    }
  }
  int ans[n + 1];
  for (int i = 1; i < n + 1; i++) ans[a[i]] = i;
  cout << "! ";
  for (int i = 1; i < n + 1; i++) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    solve();
  }
  return 0;
}

