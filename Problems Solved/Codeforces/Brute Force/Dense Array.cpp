#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",a+i);
        
        int ans = 0;
        for(int i=0; i<n-1; i++){
            int lo = min(a[i], a[i+1]);
            int hi = max(a[i], a[i+1]);
            while((hi+lo-1)/lo > 2){
                ans++;
                lo *= 2;
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}
