#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

#define sz(x) (int)x.size()

const int INF = 1e9;

int n;
vector<ii> a;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int solve(int pos = 0, int msk = 0) {
  if (pos == 10) {
    bool can = true;

    vector<vector<int>> b(sz(a), vector<int>(10, 0));

    for (int i = 0; i < 10; i++) {
      if (!(msk & (1 << i))) continue;

      for (int j = 0; j < sz(a); j++) {
        if (i > 4)
          b[j][i] = (a[j].second != i - 4) ? -1 : 1;
        else
          b[j][i] = (a[j].first != i + 1) ? -1 : 1;
      }
    }

    for (int i = 0; i < sz(a); i++) {
      for (int j = i + 1; j < sz(a); j++) {
        bool flag = false;
        for (int _ = 0; _ < 10; _++) flag |= (b[i][_] != b[j][_]);

        can &= flag;
      }
    }

    return can ? __builtin_popcount(msk) : INF;
  }

  return min(solve(pos + 1, msk), solve(pos + 1, msk | (1 << pos)));
}

int main() {
  fastIO();
  unordered_map<char, int> mp;
  int id = 1;
  for (char c : {'R', 'G', 'B', 'Y', 'W'}) {
    mp[c] = id;
    id++;
  }

  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  set<ii> check;
  for (int i = 0; i < n; i++)
    check.insert(make_pair(mp[s[i][0]], s[i][1] - '0'));

  for (auto it : check) a.push_back(it);

  printf("%d\n", solve());

  return 0;
}
