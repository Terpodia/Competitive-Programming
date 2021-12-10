#include <iostream>
using namespace std;

const int INF = 1e9;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int calc1(int n, int k, pair<int,string> a[], bool flag) {
    if(flag) {
        int ret=-INF;
        for(int i=0; i<n; i++)
            if(a[i].second == "SAFE") ret = max(ret, a[i].first);

        return ret+1;
    }

    return 2;
}

int calc2(int n, int k, pair<int,string> a[], bool flag) {
    if(flag) {
        int ret=INF;
        for(int i=0; i<n; i++)
            if(a[i].second != "SAFE") ret = min(ret, a[i].first);

        return ret-1;
    }

    return k-1;
}

int main() {
    fastIO();
    
    int n, k; cin >> n >> k;
    pair<int, string> a[n];
    for(int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;

    bool has_safe = false, has_broken = false; 

    for(int i=0; i<n; i++) 
        (a[i].second == "SAFE")? has_safe = true : has_broken = true;

    int l=calc1(n, k, a, has_safe), r=calc2(n, k, a, has_broken);

    cout << l << " " << r << "\n";

    return 0;
}
