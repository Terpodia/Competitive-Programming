#include <cstdio>
 
int main() {
    int n, m; scanf("%d%d",&n,&m);
    char a[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &a[i][j]);
 
    int ans=0;
 
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            int cnt=0;
            if(a[i][j] == '#') cnt++;
            if(a[i][j+1] == '#') cnt++;
            if(a[i+1][j] == '#') cnt++;
            if(a[i+1][j+1] == '#') cnt++;

            if(cnt==1 || cnt==3) ans++;
        }
    }
 
    printf("%d\n", ans);
 
    return 0;
}
