#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0; i<n; i++) scanf("%d",a+i);
  int hi = *max_element(a,a+n);
  int cnt=0, ans=1; 
  for(int i=0; i<n; i++){
    if(a[i] != hi) ans = max(ans, cnt), cnt = 0;
    else cnt++;
  }
  ans = max(ans, cnt);
  printf("%d\n", ans);
  return 0;
}
