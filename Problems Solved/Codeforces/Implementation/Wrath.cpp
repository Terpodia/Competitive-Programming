#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d",a+i);
    
    int ans=n;
    int suff[n]; suff[n-1] = n-1 - a[n-1];
    for(int i=n-2; i>=0; i--) suff[i] = min(suff[i+1], i - a[i]);

    for(int i=0; i<n-1; i++)
        if(suff[i+1] <= i) ans--;

    printf("%d\n", ans);

    return 0;
}
