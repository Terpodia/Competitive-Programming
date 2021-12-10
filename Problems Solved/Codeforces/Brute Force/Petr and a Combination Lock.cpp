#include <cstdio>

const int MAXN = 15;

int a[MAXN], n;
bool can=false;

void solve(int i, int deg) {
    if(i == n) {
        can |= (deg==0);
        return;
    }

    solve(i+1, (deg+a[i])%360);
    solve(i+1, (((deg-a[i])%360) + 360) % 360);
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",a+i);
    solve(0, 0);

    (!can)? puts("NO") : puts("YES");

    return 0;
}
