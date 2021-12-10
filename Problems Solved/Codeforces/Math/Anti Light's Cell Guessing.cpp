#include <cstdio>
#include <algorithm>
using namespace std;
int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n, m; aux=scanf("%d%d",&n,&m);
    if (n == 1 && m == 1) puts("0");
    else if (n == 1 || m == 1) puts("1");
    else puts("2");
  }

  return 0;
}

