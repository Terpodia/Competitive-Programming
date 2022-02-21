#include <cstdio>

typedef long double ld;

int main() {
  ld co,ca,s; 
  while(scanf("%Lf%Lf%Lf",&co,&ca,&s) != EOF) {
    ld ans=0;
    ans+=((co)/(co+ca))*((ca)/(co+ca-s-1));
    ans+=((ca)/(co+ca))*((ca-1)/(co+ca-s-1));
    printf("%.5Lf\n",ans);
  }
  return 0;
}

