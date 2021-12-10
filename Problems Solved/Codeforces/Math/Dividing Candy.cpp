#include <iostream>
#include <cstring>

#define MAX (int)1e6

const int MAXN = 1e5;

int n, a[MAXN], p[MAX];

bool solve() {
    int m = n;
    for(int i=0; i<n; i++) p[a[i]]++;

    for(int i=0; i<MAX-1; i++) {
        if(m == 2) return true;

        m -= p[i] / 2;
        p[i+1] += p[i] / 2;
        p[i] %= 2;
    }

    return false;
}

int main() { 
    memset(p, 0, sizeof(p));
    scanf("%d",&n); 
    for(int i=0; i<n; i++) scanf("%d", a+i);

    (solve())? puts("Y") : puts("N");

    return 0;
}
