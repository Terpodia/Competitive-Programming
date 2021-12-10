#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e5;

int aux, n, m, a[MAXN], p[MAXN], s[MAXN];

int solve() {
    int L[n+1]; memset(L, -1, sizeof(L));
    for (int i=0; i<m; i++) 
        L[s[i]] = max(L[s[i]], p[i]);
    
    for (int i=n-1; i>=1; i--)
        L[i] = max(L[i], L[i+1]);

    for (int i=0; i<n; i++) if (a[i] > L[1])
        return -1;

    int pos=0, ret=0;

    while (pos < n) {
        ret++; 
        int ls=-1, mx=-1;
        for (int i=1; i<=n; i++) {
            if (pos + i - 1 >= n) break;
            mx = max(mx, a[pos+i-1]);
            if (mx > L[i]) break;
            ls = i;
        }
        pos += ls; 
    }

    return ret;
}

int main() {
    int t; aux=scanf("%d",&t);
    while (t--) {
        aux=scanf("%d",&n);
        for (int i=0; i<n; i++)
            aux=scanf("%d",a+i);
        aux=scanf("%d",&m);
        for (int i=0; i<m; i++)
            aux=scanf("%d%d",p+i,s+i);

        printf("%d\n", solve());
    }

    return 0;
}

