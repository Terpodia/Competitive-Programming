#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9;

int m;

vector<int> calc(int y) {
  int k = (m * y - 8) / 9 + 1;
  vector<int> ret;

  for (int i = 0; i < k; i++) ret.push_back(9);

  int acc = m, i = 0;
  while (acc > 0) {
    ret.push_back(min(9, acc));
    if (i == 0) ret[sz(ret) - 1]--;
    acc -= 9, i++;
  }

  reverse(ret.begin(), ret.end());

  return ret;
}

void print(vector<int>& x) {
  for (int i : x) printf("%d", i);
  puts("");
}

int main() {
  scanf("%d", &m);
  if (m == 1) {
    puts("1");
    return 0;
  }

  for (int i = 0; i < 9; i++) {
    if ((m * i) % 9 == 8) {
      vector<int> ans = calc(i);
      print(ans);
      return 0;
    }
  }

  puts("-1");

  return 0;
}
