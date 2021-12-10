#include <iostream>
using namespace std;

typedef long long ll;

#define mp make_pair

const int MAXN = 1e5;
const ll INF = 1e18;

int n; ll T[MAXN], X[MAXN];
pair<ll,ll> p, t;

bool check(ll l, ll r, ll x) {
    if(l > t.second || r < t.first) return false;
    
    pair<ll,ll> s = mp(max(l, t.first), min(r, t.second));

    if(p.first <= p.second) 
        return (x >= p.first + (s.first - t.first) && x <= p.second - (-s.second + t.second));
    
    return (x <= p.first - (s.first - t.first) && x >= p.second + (-s.second + t.second));
}

int solve() {
    p = mp(0,0), t = mp(0,0);
    int ans=0;

    for(int i=0; i<n; i++) {
        bool can = check(T[i], (i==n-1)? INF : T[i+1], X[i]);

        if(t.second <= T[i]) {
            t.first = T[i];
            t.second = t.first + abs(p.second - X[i]);
            p.first = p.second;
            p.second = X[i];
        }
        
        can |= check(T[i], (i==n-1)? INF : T[i+1], X[i]);
        if(can) ans++;
    }
    
    return ans;
}

int main() {
    int _; scanf("%d",&_);
    while(_--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lld%lld",T+i, X+i);

        printf("%d\n", solve());
    }

    return 0;
}

