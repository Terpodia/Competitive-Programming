#include <iostream>
using namespace std;

int n;
string s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        cout << "X";
      else
        cout << "=";
    }
    cout << endl;
  }
}

void solve(int cnt) {
  char ans[n][n];
  int two[cnt], z = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '2') two[z++] = i;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans[i][j] = 'X';

  ans[two[0]][two[1]] = '+';
  for (int i = 2; i < cnt; i++) ans[two[0]][two[i]] = '-';
  ans[two[1]][two[2]] = '+';

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && ans[i][j] != 'X') continue;
      if (i == j)
        continue;
      else {
        if (ans[j][i] == '=' || ans[j][i] == 'X')
          ans[i][j] = '=';
        else if (ans[j][i] == '+')
          ans[i][j] = '-';
        else
          ans[i][j] = '+';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j];
    cout << endl;
  }
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> s;
    int cnt = 0;

    for (int i = 0; i < n; i++)
      if (s[i] == '2') cnt++;

    if (cnt == 1 || cnt == 2)
      cout << "NO\n";
    else {
      cout << "YES\n";
      if (cnt == 0)
        print();
      else
        solve(cnt);
    }
  }

  return 0;
}
