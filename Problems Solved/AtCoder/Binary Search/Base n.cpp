#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = unsigned long long;

#define sz(x) (int)x.size()

const ll INF = (ll)1e18 + (ll)7;
const long double OVERFLOW = (long double)1e18 * (long double)2;

string X;
ll M;

void setIO() { cin.tie(0)->sync_with_stdio(false); }

bool can(ll n) {
    ll b=1, num=0;
    for(int i=sz(X)-1; i>=0; i--) {
        if(b > M) return false;

        long double check = (long double)num + (long double)b * (long double)(X[i] - '0');

        if(check >= OVERFLOW) return false;

        num += b * (ll)(X[i] - '0');
        if(num > M) return false;

        if(i == 0) break;

        check = (long double) b * (long double) n;

        if(check >= OVERFLOW) return false;
        b *= n;
    }
    return true;
}

ll solve(ll D) {
    if(sz(X) == 1) 
        return ((ll)(X[0] - '0') > M)? 0 : 1;

    if(!can(D+1)) return 0;

    ll l = D+1, r = INF;

    while(r > l){
        ll mid = l+(r-l+1)/2;

        if(can(mid)) l = mid;
        else r = mid-1;
    }

    return l - D;
}

int main() {
    setIO();
    cin >> X >> M;

    int D=0;

    for(char c : X) {
        D = max(D, c - '0');
    }

    cout << solve(D) << "\n";

    return 0;
}

