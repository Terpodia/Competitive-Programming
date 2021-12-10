#include <cstdio>

const int P = 100057;

int main() {
    int n, m; scanf("%d%d",&n,&m);
    printf("%d %d\n", P, P);

    int p = P;

    for(int i=1; i<n && m > 0; i++) {
        if(m == 1 || i == n-1) printf("%d %d %d\n", i, i+1, p);  
        else { printf("%d %d %d\n", i, i+1, 1); p--; }
        m--; 
    }

    for(int i=1; i<n-1 && m > 0; i++) {
        for(int j=i+2; j<=n && m > 0; j++) {
            printf("%d %d %d\n", i, j, (int)1e9);
            m--;
        }
    }
    
    return 0;
}

