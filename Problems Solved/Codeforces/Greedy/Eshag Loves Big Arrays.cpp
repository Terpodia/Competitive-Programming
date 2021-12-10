#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;

int main(){
    int t; scanf("%d",&t);

    while(t--){
        int n; scanf("%d",&n);
        int a[MAXN];
        for(int i=0; i<n; i++) scanf("%d",a+i);

        sort(a, a+n);
        int cnt=0;

        for(int i=0; i<n; i++){
            cnt++;
            if(i < n && a[i+1] != a[i]) break;
        }

        printf("%d\n", n-cnt);
    }


    return 0;
}
