#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = -1, r = -1;

    for (int i = 0; i < sz(s); i++) {
      int a = 0, b = 0;
      for (int j = i; j < sz(s); j++) {
        (s[j] == 'a') ? a++ : b++;
        if (a == b) l = i + 1, r = j + 1;
      }
    }

    printf("%d %d\n", l, r);
  }

  return 0;
}
