#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

const int MAXN = 1e5;

int shirts[7];
int n;

unordered_map<string, int> mp1;
unordered_map<int, string> mp2;

pair<int, int> a[MAXN];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

void solve() {
  int ans[n];
  bool can = true;
  vector<pair<int, int>> b;

  for (int i = 0; i < n; i++) {
    if (a[i].second == 0) {
      if (shirts[a[i].first] == 0)
        can = false;
      else {
        shirts[a[i].first]--;
        ans[i] = a[i].first;
      }
    }

    else
      b.push_back(make_pair(a[i].first, i));
  }

  sort(b.begin(), b.end());

  for (int i = 0; i < sz(b); i++) {
    if (shirts[b[i].first] > 0) {
      ans[b[i].second] = b[i].first;
      shirts[b[i].first]--;
    }

    else {
      if (shirts[b[i].first + 1] == 0)
        can = false;
      else {
        ans[b[i].second] = b[i].first + 1;
        shirts[b[i].first + 1]--;
      }
    }
  }

  if (can) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << mp2[ans[i]] << "\n";
  }

  else
    cout << "NO\n";
}

int main() {
  fastIO();

  mp1["S"] = 1;
  mp1["M"] = 2;
  mp1["L"] = 3;
  mp1["XL"] = 4;
  mp1["XXL"] = 5;
  mp1["XXXL"] = 6;

  mp2[1] = "S";
  mp2[2] = "M";
  mp2[3] = "L";
  mp2[4] = "XL";
  mp2[5] = "XXL";
  mp2[6] = "XXXL";

  cin >> shirts[1] >> shirts[2] >> shirts[3] >> shirts[4] >> shirts[5] >>
      shirts[6] >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i].first = a[i].second = 0;

    bool flag = false;
    string aux;

    for (int j = 0; j < sz(s); j++) {
      if (s[j] == ',') {
        flag = true;
        a[i].first = mp1[aux];
        aux.clear();
        continue;
      }

      aux.push_back(s[j]);
    }

    (flag) ? a[i].second = mp1[aux] : a[i].first = mp1[aux];
  }

  solve();

  return 0;
}
