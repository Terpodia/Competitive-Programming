#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
using  ll = long long;
using p = pair<ll, int>;

const int MAXN = 1e4;
const ll INF = 1e18;

int N; ll a[MAXN];

vector<ll> first_right() {
    stack<p> s;
    vector<ll> ret(N);

    for(int i=N-1; i>=0; i--){
        while(!s.empty() && s.top().first >= a[i]) {
            s.pop();
        }
        ret[i] = (s.empty())? N : s.top().second;
        s.push( {a[i], i} );
    }

    return ret;
}

vector<ll> first_left() {
    stack<p> s;
    vector<ll> ret(N);

    for(int i=0; i<N; i++){
        while(!s.empty() && s.top().first >= a[i]) {
            s.pop();
        }

        ret[i] = (s.empty())? -1 : s.top().second;
        s.push( {a[i], i} );
    }

    return ret;
}

ll solve() {
    vector<ll> R = first_right();
    vector<ll> L = first_left();

    ll ans=-INF;

    for(int i=0; i<N; i++) {
        ll l = L[i]+1, r = R[i]-1;
        ans = max(ans, (r - l + 1) * a[i]);
    }

    return ans;
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%lld",a+i);

    printf("%lld\n", solve());

    return 0;
}
