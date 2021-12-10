#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> v(n); 
        for(int i=0; i<n; i++) scanf("%d",&v[i]);

        bool flag = false;

        for(int i=0; i<n; i++){
            double root = sqrt(v[i]);
            int r = (int)root;
            if(r*r != v[i]) { flag = true; break; }
        }

        if(!flag) puts("NO");
        else puts("YES");
    }

    return 0;
}
