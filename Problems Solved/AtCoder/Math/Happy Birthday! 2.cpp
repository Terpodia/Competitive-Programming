#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int a[N];
  for (int i = 0; i < N; i++) scanf("%d", a + i);

  int m = min(8, N);

  vector<vector<int>> sequences[200];

  for (int msk = 1; msk < (1 << m); msk++) {
    vector<int> s;
    int sum = 0;

    for (int i = 0; i < 8; i++) {
      if (msk & (1 << i)) {
        sum = (sum + a[i]) % 200;
        s.push_back(i);
      }
    }

    sequences[sum].push_back(s);

    if (sequences[sum].size() > 1) {
      puts("Yes");
      printf("%d ", (int)sequences[sum][0].size());
      for (int& x : sequences[sum][0]) printf("%d ", x + 1);
      puts("");

      printf("%d ", (int)sequences[sum][1].size());
      for (int& x : sequences[sum][1]) printf("%d ", x + 1);
      puts("");
      return 0;
    }
  }

  puts("No");

  return 0;
}
