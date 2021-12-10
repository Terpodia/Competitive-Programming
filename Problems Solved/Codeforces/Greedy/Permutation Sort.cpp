#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n); vector<int> a(n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        
        bool flag = true;
        for(int i=1; i<n; i++) if(a[i] < a[i-1]) flag = false;

        if(flag) puts("0");
        else{
            if(a[0] == 1 || a[n-1] == n) puts("1");
            else if(a[0] == n && a[n-1] == 1) puts("3");
            else puts("2");
        }
    }


    return 0;
}
