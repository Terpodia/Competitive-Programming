#include <fstream>
#include <iostream>
using namespace std;

const int MAXN = 1e5;

int N, K, B, s[MAXN];

int solve() {
  int ans, sum = 0;
  for (int i = 0; i < K; i++) {
    sum += s[i];
  }

  ans = K - sum;
  int l = 0;

  for (int r = K; r < N; r++) {
    sum -= s[l];
    l++;
    sum += s[r];

    ans = min(ans, K - sum);
  }

  return ans;
}

int main() {
  ifstream fin("maxcross.in");
  ofstream fout("maxcross.out");

  fin >> N >> K >> B;
  for (int i = 0; i < N; i++) s[i] = 1;

  for (int i = 0; i < B; i++) {
    int j;
    fin >> j;
    s[j - 1] = 0;
  }

  fout << solve() << "\n";

  return 0;
}
