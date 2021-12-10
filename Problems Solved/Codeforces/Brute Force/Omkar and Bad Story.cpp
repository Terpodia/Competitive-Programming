#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n, a[100];
        bool ok[101];

        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i);

        memset(ok, false, sizeof(ok));

        bool can=true;
        for(int i=0; i<n; i++) if(a[i] < 0) can = false;

        if(!can) { puts("NO"); continue; }

        puts("YES");

        int k=101;
        vector<int> ans;

        for(int i=0; i<n; i++) {
            ok[a[i]] = true;
            ans.push_back(a[i]);
        }

        for(int i=0; i<=100; i++) 
            if(!ok[i]) ans.push_back(i);

        printf("%d\n", k);
        for(int i=0; i<k; i++) printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}
