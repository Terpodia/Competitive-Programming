#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

int main(){
  int n; scanf("%d",&n);
  int a[n];
  for(int i=0; i<n; i++) scanf("%d",a+i);
  pair<int,int> c[n];
  for(int i=0; i<n; i++) c[i] = {a[i],i};
  sort(c,c+n);
  int ans = 1;
  for(int i=0; i<n-1; i++){
    if(c[i].snd > c[i+1].snd) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
