#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  puts("1");
  int m = rand(1, 8), n = rand(8, 100), k = rand(0, 200);
  k -= 100;
  printf("%d %d %d\n", m, n, k);
  for (int i = 0; i < m; i++) {
    int x = rand(0, 20);
    x -= 10;
    printf("%d ", x);
  }
  puts("");
  return 0;
}
