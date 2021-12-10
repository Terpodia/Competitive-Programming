#include <iostream>
#include <string>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    ll A, B; aux=scanf("%lld%lld",&A,&B);
    printf("%lld\n", A * (to_string(B+1).size() - 1)); 
  }

  return 0;
}

