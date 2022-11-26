#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MAXN = 5e4;
int N;
ll cows[MAXN];

int solve() {
  int ans = 0;
  ll s = 0;
  vector<int> d(7, -1);

  for (int i = 0; i < N; i++) {
    s += cows[i];
    if (s % 7 == 0)
      ans = max(ans, i + 1);
    else if (d[s % 7] != -1 && d[s % 7] < i) {
      int r = i, l = d[s % 7] + 1;
      ans = max(ans, r - l + 1);
    }
    if (d[s % 7] == -1) d[s % 7] = i;
  }

  return ans;
}

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("div7.in");
  fout.open("div7.out");

  fin >> N;
  for (int i = 0; i < N; i++) fin >> cows[i];

  fout << solve() << "\n";

  fin.close();
  fout.close();
  return 0;
}
