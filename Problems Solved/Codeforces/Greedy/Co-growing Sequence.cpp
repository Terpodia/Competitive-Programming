#include <bits/stdc++.h>
using namespace std;

int main(){
  int tt;
  scanf("%d",&tt);
  while(tt--){
    int n;
    scanf("%d",&n);
    int x[n];
    for(int i=0; i<n; i++) scanf("%d",x+i);
    printf("0 ");

    int p=x[0];
    for(int i=1; i<n; i++){
      int y=0;
      for(int j=0; j<30; j++){
        if((p & (1 << j)) && !(x[i] & (1 << j))) 
          y |= 1<<j;
      }
      printf("%d ", y);
      p = x[i] ^ y;
    }
    puts("");
  }
  return 0;
}
