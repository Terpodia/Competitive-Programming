#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 5000;
int n; ll x;
vector<pair<ll,ll>> k;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    ll a, b, c;
    bool flag = false;
    
    sort(k.begin(), k.end());

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll w = x - k[i].first - k[j].first;
            pair<ll,ll> pa = {w, 0};
            if(w <= 0) continue;
             
            auto it = lower_bound(k.begin(), k.end(), pa);
            if(it == k.end() || it->first != w) continue;
            else{
                int p = distance(k.begin(), it);
                while(p == i || p == j) p++;
                if(p >= n || k[p].first != w) continue; 
                else{
                    flag = true; a=k[i].second; b=k[j].second; c=k[p].second;
                }     
            }
            if(flag) break;
            
        }
        if(flag) break;
    }
    

    if(flag) cout << a+1 << " " << b+1 << " " << c+1 << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main(){
    fastIO();
    cin >> n >> x;
    k.resize(n);
    for(int i=0; i<n; i++){
        cin >> k[i].first;
        k[i].second = i;
    }
    solve();  

    return 0;
}
