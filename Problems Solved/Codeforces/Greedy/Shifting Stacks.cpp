#include <cstdio>

typedef long long ll;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        ll h[n];
        for(int i=0; i<n; i++)
            scanf("%lld",h+i);
        
        bool f = true;
        
        for(int i=0; i<n-1; i++){
            if(i==0){
                h[i+1] += h[i];
                h[i] -= h[i];
            }
            else if(h[i] > 0){
                h[i+1] += h[i]-h[i-1]-1;
                h[i] -= h[i]-h[i-1]-1;
            }

            if(h[i] >= h[i+1]){
                f = false;
                break;
            }
        }

        if(f) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
