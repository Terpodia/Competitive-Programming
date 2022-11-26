#include <algorithm>
#include <fstream>
using namespace std;

const int MAXN = 1e5;

char GJ[MAXN];
int N, s1[MAXN + 1], s2[MAXN + 1], s3[MAXN + 1];

void buildPsum(int s[], char c) {
  for (int i = 1; i <= N; i++) {
    if (GJ[i - 1] == c) s[i] = 1;
    s[i] += s[i - 1];
  }
}

int solve() {
  int ans = 0;
  buildPsum(s1, 'H');
  buildPsum(s2, 'P');
  buildPsum(s3, 'S');

  for (int i = 1; i <= N - 1; i++) {
    int pref = max(s1[i], max(s2[i], s3[i]));
    int suff = max(s1[N] - s1[i], max(s2[N] - s2[i], s3[N] - s3[i]));
    ans = max(ans, pref + suff);
  }

  return ans;
}

int main() {
  ifstream fin("hps.in");
  ofstream fout("hps.out");

  fin >> N;
  for (int i = 0; i < N; i++) fin >> GJ[i];

  fout << solve() << "\n";

  return 0;
}
