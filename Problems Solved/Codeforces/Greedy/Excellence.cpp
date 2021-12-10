#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;

int n, a[MAXN];

int solve() {
    int l=0, r=n-1, ret = 1e9;

    while(r > l) {
        ret = min(ret, a[r] + a[l]);
        l++; r--;
    }

    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",a+i);
    sort(a, a+n);

    printf("%d\n", solve());

    return 0;
}
