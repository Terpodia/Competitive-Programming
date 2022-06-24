#include <deque>
#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    deque<char> ans;

    if (n2 > 0 || n1 > 0) ans.push_back('1');

    for (int i = 0; i < n2; i++) {
      ans.push_back('1');
    }
    if (n1 > 0 && n1 % 2 == 0) {
      ans.push_front('0');
      n1--;
    }
    for (int i = 0; i < n1; i++) {
      if (i % 2 == 0)
        ans.push_back('0');
      else
        ans.push_back('1');
    }
    if (n2 == 0 && n1 == 0) ans.push_back('0');
    for (int i = 0; i < n0; i++) ans.push_back('0');
    for (char i : ans) cout << i;
    cout << "\n";
  }
  return 0;
}

