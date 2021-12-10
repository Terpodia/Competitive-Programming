#include <cstdio>
#include <cmath>
int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n, d; aux=scanf("%d%d",&n,&d);
    int x1 = (int)floor(sqrt(d))-1, x2 = (int)ceil(sqrt(d))-1;

    if (x1 + (d+x1)/(x1+1) <= n || x2 + (d+x2)/(x2+1) <= n) puts("YES");
    else puts("NO");
  }

  return 0;
}

