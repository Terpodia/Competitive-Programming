#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n; ll a[MAXN], t; 

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    ll s=0; int l=0, res=0;
    for(int r=0; r<n; r++){
        s += a[r];
        while(s > t){
            s -= a[l]; l++;
        }
        if(l <= r) res = max(res, r-l+1);
    }
    cout << res << "\n";
}

int main(){
    fastIO();
    cin >> n >> t;
    for(int i=0; i<n; i++) cin >> a[i];
    solve();
    return 0;
}
