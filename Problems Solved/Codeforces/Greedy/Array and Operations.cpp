#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int aux;

#define sz(x) (int)x.size()

const int MAXA = 2e5 + 7;

int main() {
  int TC;
  aux = scanf("%d", &TC);
  while (TC--) {
    int n, k;
    aux = scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n - 2 * k; i++) ans += a[i];

    vector<int> vec;

    for (int i = n - 2 * k; i < n; i++) vec.push_back(a[i]);

    int i = 0;

    while (i + k < sz(vec)) ans += vec[i] / vec[i + k], i++;

    printf("%d\n", ans);
  }

  return 0;
}
