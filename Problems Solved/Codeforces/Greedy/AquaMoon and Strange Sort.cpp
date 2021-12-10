#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using vp = vector<pair<int,int>>;

#define mp make_pair

const int MAXN = 1e5+7;

int n, a[MAXN];

void solve() {
    vp cnt1(MAXN, mp(0, 0)), cnt2(MAXN, mp(0, 0)); 
    for(int i=0; i<n; i++) {
        (i%2==0)? cnt1[a[i]].first++ : cnt1[a[i]].second++;
    }

    sort(a, a+n);
    for(int i=0; i<n; i++) {
        (i%2==0)? cnt2[a[i]].first++ : cnt2[a[i]].second++;
    }

    bool can = true;

    for(int i=0; i<MAXN; i++) {
        can &= (cnt1[i] == cnt2[i]);
    }

    (can)? puts("YES") : puts("NO");
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i);
        solve();
    }

    return 0;
}
