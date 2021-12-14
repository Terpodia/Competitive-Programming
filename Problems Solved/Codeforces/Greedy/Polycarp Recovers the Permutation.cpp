#include <cstdio>
int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n; aux=scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) aux=scanf("%d",a+i);

    if (a[0] != n && a[n-1] != n) puts("-1");
    else {
      for (int i=n-1; i>-1; i--) printf("%d ", a[i]);
      puts("");
    }
  }


  return 0;
}

