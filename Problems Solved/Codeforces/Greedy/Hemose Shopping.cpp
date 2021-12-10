#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n, x; aux=scanf("%d%d",&n,&x);
    int a[n]; 
    for (int i=0; i<n; i++)
      aux=scanf("%d",a+i);

    if (x*2 <= n) { puts("YES"); continue; }
    
    vector<int> v;

    for (int i=0; i<n; i++) if (i < n - x || n - 1 - i < n - x)
      v.push_back(a[i]);

    sort(v.begin(), v.end());

    int j=0;

    for (int i=0; i<n; i++) if (i < n - x || n - 1 - i < n - x)
      a[i] = v[j++];

    bool can = true;

    for (int i=0; i<n-1; i++)
      if (a[i] > a[i+1]) can = false;

    (can) ? puts("YES") : puts("NO");
  }

  return 0;
}

