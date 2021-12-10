#include <cstdio>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        if(n==2) puts("-1");
        else{
            int z=1;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(z > n*n) z = 2;
                    printf("%d ", z);
                    z += 2;
                }
                puts("");
            }
        }
    }

    return 0;
}
