#include <iostream>
#include <vector>
using namespace std;

int aux;

int main() {
  int t; aux=scanf("%d",&t); 
  while (t--) {
    int n, m; aux=scanf("%d%d",&n,&m);
    int a[m][3]; 
    for (int i=0; i<m; i++) 
      aux=scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

    vector<bool> ok(n, true);

    for (int i=0; i<m; i++)
      ok[a[i][1]-1] = false;

    int j=-1;
    for (int i=0; i<n; i++)
      if (ok[i]) j=i;

    for (int i=0; i<n; i++) if (j != i) {
      printf("%d %d\n", j+1, i+1);
    }
  }

  return 0;
}

