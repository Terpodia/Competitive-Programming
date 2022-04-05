#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1e4 + 10;

int main() {
  int numDiv[MAX];
  numDiv[0] = 0;
  for (int i = 1; i < MAX; i++) numDiv[i] = 1;

  for (int j = 2; j < MAX; j += 2) {
    int cnt = 0, k = j;
    while (k % 2 == 0) cnt++, k /= 2;
    numDiv[j] *= cnt + 1;
  }
  for (int i = 3; i < MAX; i += 2) {
    if (numDiv[i] == 1) {
      for (int j = i; j < MAX; j += i) {
        int cnt = 0, k = j;
        while (k % i == 0) cnt++, k /= i;
        numDiv[j] *= cnt + 1;
      }
    }
  }

  int tt;
  scanf("%d", &tt);

  while (tt--) {
    int l, r;
    scanf("%d%d", &l, &r);
    vector<int> ans;
    for (int i = l; i <= r; i++) {
      if (numDiv[numDiv[i]] == 2) ans.push_back(i);
    }
    if (ans.empty())
      puts("-1");
    else {
      for (int i = 0; i < (int)ans.size(); i++)
        printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
    }
  }
  return 0;
}

