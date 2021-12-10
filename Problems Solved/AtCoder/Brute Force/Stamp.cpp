#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 1e9

int main() {
    int N, M; scanf("%d%d",&N, &M);
    int a[M+2];

    a[0]=0, a[M+1]=N+1;
    for(int i=1; i<=M; i++) scanf("%d",a+i);

    sort(a, a+M+2);

    int lo=INF;
    for(int i=0; i<=M; i++) 
        if(a[i+1]-a[i]-1 > 0) lo = min(lo, a[i+1]-a[i]-1);
    
    int ans=0;

    for(int i=0; i<=M; i++) {
        int sz = a[i+1] - a[i] - 1;
        
        ans += (sz+lo-1)/lo;
    }

    printf("%d\n", ans);

    return 0;
}
