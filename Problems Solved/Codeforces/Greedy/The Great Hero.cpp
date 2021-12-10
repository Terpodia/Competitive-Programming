#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1e5;
 
pair<ll, ll> m[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

bool c(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

void solve(ll A, ll B, int n){
    sort(m, m+n, c);

    for(int i = 0; i < n; i++){
        ll r = (m[i].second + A - 1) / A;
        ll d = (B + m[i].first - 1) / m[i].first;
        if(r > d){
            cout << "NO\n";
            return;
        }
        else if(r == d && i < n-1){
            cout << "NO\n";
            return;
        }
        
        else{
            B -= m[i].first * r;
        }
    }
 
    cout << "YES\n";
}
 
int main(){
    fastIO();
 
    int t; cin >> t;
    while(t--){
        ll A, B; int n; cin >> A >> B >> n;
        for(int i = 0; i < n; i++)
            cin >> m[i].first;
        
        for(int i = 0; i < n; i++)
            cin >> m[i].second;
 
        solve(A, B, n);
    }
 
 
    return 0;
}
