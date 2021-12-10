#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

const int MAXN = 5000;

ll x; int n;
ii a[MAXN]; 

void solve(){
    pair<ii,ll> res;
    bool flag = false;
    int p=0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            while(p < n && a[i].first + a[j].first + a[p].first < x) p++;               
            while(p-1 >= 0 && a[i].first + a[j].first + a[p-1].first >= x) p--;
            while((p == i || p == j) && p != n-1) p++; 

            if(p == i || p == j) continue;
            if(a[p].first + a[i].first + a[j].first == x){
                flag = true; res = {{a[p].second, a[j].second}, a[i].second};
            }
        }
    }

    if(flag) cout << res.first.first << " " << res.first.second << " " << res.second << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main(){
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    
    sort(a, a+n);
    solve();

    return 0;
}
