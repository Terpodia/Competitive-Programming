#include <iostream>
#include <algorithm>
using namespace std;

struct movie{
    int l, r;
    bool operator<(const movie &m){
        if(m.r != r) return r < m.r;
        return l < m.l;
    }
};

const int MAXN = 2 * 1e5;
int n;
movie a[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    sort(a, a+n);
    movie current = a[0];
    int ans = 1;

    for(int i=1; i<n; i++){
        if(a[i].l < current.r) continue;
        ans++;
        current = a[i];
    }
    cout << ans << "\n";
}

int main(){
    fastIO();
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i].l >> a[i].r;
    solve();

    return 0;
}
