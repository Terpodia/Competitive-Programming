#include <cstdio>

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        bool flag = false;
        for(int x = 0; x*2020 <= n; x++){
            if((n - 2020*x) % 2021 == 0){flag=true;}
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
