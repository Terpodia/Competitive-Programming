#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 65536;
int N, K;
ll a[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

ll solve(){
    vector<ll> v, d;
    for(int i=0; i<N; i++) v.push_back(a[i]/12);
    v.push_back(-1);

    ll res = (v[0]+1)*12; K--;
    
    for(int i=0; i<(int)v.size()-1; i++){
        ll x1 = (v[i]+1)*12, x2 = (v[i+1]+1)*12;
        ll r = abs(x1 - x2);
        if(r > 12) d.push_back(r-12);
    }

    sort(d.begin(), d.end(), greater<ll>());
    for(ll i : d){
        if(K==0) break;
        else{
            res -= i; K--;
        }
    }

    return res;
}

int main(){
    fastIO();
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N, greater<ll>());

    cout << solve() << "\n";

    return 0;
}
