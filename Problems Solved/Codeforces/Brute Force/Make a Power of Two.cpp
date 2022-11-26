#include <algorithm>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9;

string power_two[63];
string n;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int check(string& a, string& b) {
  int i = 0, j = 0;

  string k = "";

  int ret = 0;

  while (i < sz(a) || j < sz(b)) {
    if (i >= sz(a))
      break;
    else if (j >= sz(b)) {
      ret += sz(a) - i;
      break;
    }

    if (a[i] == b[j])
      k.push_back(a[i]);
    else {
      ret++;
      i++;
      continue;
    }
    i++, j++;
  }

  return ret + abs(sz(b) - sz(k));
}

int calc(string& p) {
  int ret = INF;

  for (int i = 0; i < sz(n); i++) {
    string a = "";

    for (int j = 0; i + j < sz(n); j++) {
      a.push_back(n[i + j]);
      ret = min(ret, i + (sz(n) - 1 - (i + j)) + check(a, p));
    }
  }

  return ret;
}

int solve() {
  int ret = INF;
  for (int i = 0; i < 60; i++) {
    ret = min(ret, calc(power_two[i]));
  }

  return ret;
}

int main() {
  fastIO();
  for (long long i = 0; i < 63; i++) power_two[i] = to_string((1LL << i));

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    printf("%d\n", solve());
  }

  return 0;
}
