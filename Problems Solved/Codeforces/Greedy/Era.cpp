#include <cstdio>

typedef long long ll;

int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n; aux=scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) aux=scanf("%d",a+i);
  
    ll acc=0;   
    
    for (ll i=1; i<=n; i++) {
      ll curr = i+acc;
      if (a[(int)i-1] > curr) {
        acc += a[(int)i-1] - curr;
      }
    }

    printf("%lld\n", acc);
  }

  return 0;
}

