#include <iostream>
using namespace std;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int a = s1.size(), b = s2.size();
    int c = lcm(a, b);
    string aux1 = s1, aux2 = s2;

    for (int i = 1; i < c / a; i++) {
      s1 += aux1;
    }

    for (int i = 1; i < c / b; i++) {
      s2 += aux2;
    }

    if (s1 != s2)
      cout << "-1\n";
    else
      cout << s1 << "\n";
  }
  return 0;
}
