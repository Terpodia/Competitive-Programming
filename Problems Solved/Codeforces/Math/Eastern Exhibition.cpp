#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        ll x[n], y[n];        
        for(int i=0; i<n; i++){
            scanf("%lld%lld",x+i, y+i);
        }
        sort(x, x+n); sort(y, y+n);
        ll r1 = abs(x[(n+1)/2-1] - x[(n+2)/2-1]) + 1;
        ll r2 = abs(y[(n+1)/2-1] - y[(n+2)/2-1]) + 1;
        printf("%lld\n", r1 * r2);
    }

    return 0;
}
