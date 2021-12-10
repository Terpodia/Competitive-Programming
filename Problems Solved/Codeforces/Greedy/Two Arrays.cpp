#include <cstdio>
#include <algorithm>
using namespace std;
int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n; aux=scanf("%d",&n);

    int a[n], b[n];
    for (int i=0; i<n; i++)
      aux=scanf("%d",a+i);
    for (int i=0; i<n; i++)
      aux=scanf("%d",b+i);

    sort(a,a+n); sort(b,b+n);

    bool can=true;

    for (int i=0; i<n; i++) {
      if (a[i] > b[i]) can = false;
      else if (a[i] < b[i] && b[i] - a[i] > 1) can = false;
    }

    (can) ? puts("YES") : puts("NO");
  }

  return 0;
}

