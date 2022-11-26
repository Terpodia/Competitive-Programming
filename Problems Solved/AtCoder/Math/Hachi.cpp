#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

string S;

int cnt[10];

bool calc(const int MIN, const int MAX) {
  int i = MIN;
  while (i < MAX) {
    string a = to_string(i);
    vector<int> cnt2(10, 0);
    for (char c : a) cnt2[c - '0']++;

    bool can = true;

    for (char c : a) can &= (cnt[c - '0'] >= cnt2[c - '0']);

    if (can) return can;
    i += 8;
  }

  return false;
}

void solve() {
  if (sz(S) == 1) {
    (S[0] == '8') ? cout << "Yes\n" : cout << "No\n";
    return;
  }

  for (int i = 0; i < sz(S); i++) cnt[S[i] - '0']++;

  if (sz(S) == 2) {
    (calc(16, 100)) ? cout << "Yes\n" : cout << "No\n";
    return;
  }

  (calc(104, 1000)) ? cout << "Yes\n" : cout << "No\n";
}

int main() {
  fastIO();
  cin >> S;

  solve();
  return 0;
}
