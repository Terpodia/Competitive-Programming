#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

const int MAXN = 2e5, INF = 1e9;

int n, h[MAXN];

void solve() {
    int lo=INF;
    sort(h, h+n);

    for(int i=0; i<n-1; i++) lo = min(lo, h[i+1] - h[i]);

    int a, b;

    for(int i=0; i<n-1; i++) {
        if(h[i+1] - h[i] == lo) {
            a = i, b = i+1;
            break;
        }
    }

    deque<int> ans;
    for(int i=b+1; i<n; i++) ans.push_back(h[i]);
    for(int i=0; i<a; i++) ans.push_back(h[i]);

    ans.push_front(h[a]);
    ans.push_back(h[b]);

    for(int i : ans) printf("%d ", i);
    puts("");
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d",&n); 
        for(int i=0; i<n; i++) scanf("%d",h+i);
        
        solve();
    }

    return 0;
}
