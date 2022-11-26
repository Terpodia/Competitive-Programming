#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool can(string s) {
  for (int i = 0; i < (int)s.size() - 1; i++)
    if (s[i] - '0' > s[i + 1] - '0') return false;

  return true;
}

bool calc(string s, vector<int> v) {
  int m = (int)v.size();

  for (int i = (int)s.size() - 1; i >= 0; i--) {
    if (s[i] == '0') v.push_back(i);
    if ((int)v.size() == m * 2) break;
  }

  sort(v.begin(), v.end());

  string a = s;

  int p1 = 0, p2 = (int)v.size() - 1;

  while (p1 < p2) {
    swap(a[v[p1]], a[v[p2]]);
    p1++, p2--;
  }

  if (!can(a)) return false;

  cout << v.size() << " ";
  for (int i : v) cout << i + 1 << " ";
  cout << "\n";

  return true;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (can(s))
      cout << "0\n";

    else {
      cout << 1 << "\n";
      vector<int> v;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          v.push_back(i);
          if (calc(s, v)) break;
        }
      }
    }
  }

  return 0;
}
