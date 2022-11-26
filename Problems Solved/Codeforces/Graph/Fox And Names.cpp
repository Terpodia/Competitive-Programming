#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

bool can = true;
vector<int> G[26], ok(26, 0);
stack<int> x;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

void DFS(int u) {
  ok[u] = 1;
  for (int v : G[u]) {
    if (ok[v] == 1)
      can = false;
    else if (!ok[v])
      DFS(v);
  }

  ok[u] = 2;
  x.push(u);
}

void solve() {
  for (int i = 0; i < 26; i++) {
    if (!ok[i]) DFS(i);
  }

  if (!can)
    cout << "Impossible\n";
  else {
    while (!x.empty()) {
      cout << (char)(x.top() + 'a');
      x.pop();
    }
    cout << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool diff = false;
      for (int c = 0; c < min(sz(s[i]), sz(s[j])); c++) {
        if (s[i][c] != s[j][c]) {
          diff = true;
          G[s[i][c] - 'a'].push_back(s[j][c] - 'a');
          break;
        }
      }

      if (!diff && sz(s[i]) > sz(s[j])) can = false;
    }
  }

  solve();

  return 0;
}
