#include <iostream>
#include <algorithm>
using namespace std;
int aux;

const int MAXN = 2e5;

int n, k, a[MAXN];

void solve() {
  int i=0, j=1;
  
  int ans=n;

  while (i < n && j < n) {
    if (i == j) j++;
    else if (a[i] <= a[j] || a[i] > a[j] + k) i++;
    else ans--, j++;
  }

  printf("%d\n", ans);
}

int main() {
  aux=scanf("%d%d",&n,&k); 
  for (int i=0; i<n; i++)
   aux=scanf("%d",a+i); 

  sort(a, a+n, greater<int>());
  solve();

  return 0;
}

