#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t; scanf("%d",&t);

    while(t--){
        int n; scanf("%d",&n);
        int a[2*n]; for(int i=0; i<2*n; i++) scanf("%d", a+i);

        sort(a, a+(2*n));

        int b[2*n]; 
        b[0] = a[0]; b[2*n - 1] = a[2*n - 1];

        int x = 1, y = 2*n - 2;

        for(int i=1; i < 2*n -1; i++){
            if(i % 2 != 0) { b[i] = a[y]; y--; }
            else { b[i] = a[x]; x++; }
        }

        for(int i=0; i<2*n; i++) printf("%d ", b[i]);
        puts("");
    }


    return 0;
}
