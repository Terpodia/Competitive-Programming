#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

vector<string> cards;

int f(string s) {
  if (isdigit(s[0]) && s[0] - '0' > 1) return s[0] - '0';
  return 10;
}

void solve() {
  int y = 0;

  for (int _ = 0; _ < 3; _++) {
    vector<string> hands;
    for (int i = 0; i < 25; i++) {
      hands.push_back(cards.back());
      cards.pop_back();
    }
    int x = f(cards.back());
    y += x;
    cards.pop_back();
    for (int i = 0; i < 10 - x; i++) cards.pop_back();
    while (!hands.empty()) {
      cards.push_back(hands.back());
      hands.pop_back();
    }
  }
  printf("%s\n", cards[y - 1].c_str());
}

int main() {
  int tt, tc = 1;
  scanf("%d", &tt);
  while (tt--) {
    for (int i = 0; i < 52; i++) {
      char c[4];
      scanf(" %s", c);
      cards.push_back(string(c));
    }
    printf("Case %d: ", tc++);
    solve();
    cards.clear();
  }
  return 0;
}
