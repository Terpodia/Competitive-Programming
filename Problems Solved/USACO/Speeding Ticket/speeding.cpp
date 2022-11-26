#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

const int MAXN = 100;
int N, M;

pair<int, int> a[MAXN], b[MAXN];

int solve() {
  int ans = 0;
  int i, j;
  i = j = 0;

  while (i < N && j < M) {
    int r = a[i].first;

    a[i].first -= b[j].first;
    b[j].first -= r;

    ans = max(ans, max(b[j].second - a[i].second, 0));

    if (a[i].first <= 0) i++;
    if (b[j].first <= 0) j++;
  }

  return ans;
}

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("speeding.in");
  fout.open("speeding.out");

  fin >> N >> M;
  for (int i = 0; i < N; i++) fin >> a[i].first >> a[i].second;
  for (int i = 0; i < M; i++) fin >> b[i].first >> b[i].second;

  fout << solve() << "\n";

  fin.close();
  fout.close();
  return 0;
}
