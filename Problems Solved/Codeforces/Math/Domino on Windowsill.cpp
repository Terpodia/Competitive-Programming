#include <cstdio>

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,k1,k2,w,b;
        scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
        
        int cntw = k1 + k2, cntb = (n-k1) + (n-k2);
        
        w*=2; b*=2;

        if(cntw >= w && cntb >= b) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
