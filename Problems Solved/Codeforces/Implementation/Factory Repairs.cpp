#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;

struct segment_tree {
    vector<ll> sum;
    segment_tree(int n) { sum = vector<ll>(4*n,0); }
    
    void build(int p, int lx, int rx, vector<ll>& a) {
        if(lx == rx) sum[p] = a[lx];
        else {
            int m = (lx + rx) / 2;
            build(p*2, lx, m, a);
            build(p*2+1, m+1, rx, a);
            sum[p] = sum[p*2] + sum[p*2+1];
        }
    }

    ll calc(int l, int r, int p, int lx, int rx) {
        if(lx > r || rx < l) return 0;
        if(lx >= l && rx <= r) return sum[p];

        int m = (lx + rx) / 2;
        return calc(l, r, p*2, lx, m) + calc(l, r, p*2+1, m+1, rx); 
    }

    void update(int i, int lx, int rx, int p, vector<ll>& a) {
        if(lx == rx) { sum[p] = a[i]; return; }
        
        int m = (lx + rx) / 2;
        if(i <= m) update(i, lx, m, p*2, a);
        else update(i, m+1, rx, p*2+1, a);

        sum[p] = sum[p*2] + sum[p*2+1];
    }
};

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();

    int n,k,q; ll a, b; cin >> n >> k >> a >> b >> q;
    segment_tree st1(n), st2(n);

    vector<ll> d1(n, 0), d2(n, 0);

    st1.build(1, 0, n-1, d1);
    st2.build(1, 0, n-1, d2);


    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int d; ll p; cin >> d >> p;
            d1[d-1] = min(a, d1[d-1] + p);
            d2[d-1] = min(b, d2[d-1] + p);

            st1.update(d-1, 0, n-1, 1, d1);
            st2.update(d-1, 0, n-1, 1, d2);
        }
        
        else {
            ll p, ans=0; cin >> p; 

            if(p-2 >= 0) ans += st2.calc(0, p-2, 1, 0, n-1);
            if(p+k-1 < n) ans += st1.calc(p+k-1, n-1, 1, 0, n-1);

            cout << ans << "\n";
        }
    }


    return 0;
}
