#include <iostream>
using namespace std;
using ll = long long;
using ld = long double;

const ld OVERFLOW = 1e18 + (ld)7;

ll X, Y, A, B;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool can(ll cnt) { 
    ll x = X; 

    for(ll i=0; i<=64; i++) {
        if(i + (Y-x-1)/B >= cnt) return true; 

        ld m = (ld)x * (ld)A; 
        if(m >= OVERFLOW) break;

        x *= A;
        if(x >= Y) break;
    }

    return false;
}

ll solve() { 
    ll l = 0, r = 1e18;

    while(r > l) {
        ll mid = l + (r-l+1)/2;
        if(can(mid)) l = mid;
        else r = mid-1;
    }
    
    return l;
}

int main() {
    fastIO();
    cin >> X >> Y >> A >> B; 

    cout << solve() << "\n";

    return 0;
}
