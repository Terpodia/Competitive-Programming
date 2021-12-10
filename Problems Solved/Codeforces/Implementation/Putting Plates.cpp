#include <iostream>
#include <cstring>
using namespace std;

int n, m;

void solve() {
    int ans[n][m];
    memset(ans, 0, sizeof(ans));

    ans[0][0]=1, ans[0][1]=-1, ans[1][0]=-1, ans[1][1]=-1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i != 0 && i != n-1 && j != 0 && j != m-1) continue;
            if(ans[i][j] != 0) continue;

            for(int _=-1; _<=1; _++) {
                for(int __=-1; __<=1; __++) {
                    if(i+_ < 0 || i+_ >= n || j+__ < 0 || j+__ >= m) continue;
                    ans[i+_][j+__] = -1;
                }
            }

            ans[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            (ans[i][j]==1)? printf("1") : printf("0");
        puts("");
    }

    puts("");
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        solve();
    }


    return 0;
}
