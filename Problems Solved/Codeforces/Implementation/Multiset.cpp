#include <iostream>
#include <cstring>
using namespace std;

#define FOR(i,x,n) for(int i = (x); i < (int)(n); i++)
#define LSOne(x) (x) & (-x)

const int MAXN = 1e6+1;

struct fenwic_tree {
    int ft[MAXN];
    void init() { memset(ft, 0, sizeof(ft)); }
    
    void build(int f[]) {
        FOR(i,1,MAXN) {
            ft[i] += f[i];
            if(i + (LSOne(i)) < MAXN) 
                ft[i+(LSOne(i))] += ft[i];
        }
    }

    int psum(int r) {
        int ret=0;
        for(int i=r; i>0; i-=LSOne(i)) ret += ft[i];
        return ret;
    }

    int sum(int l, int r) { return psum(r) - psum(l-1); }

    void update(int i, int x) {
        for(; i<MAXN; i+=LSOne(i)) ft[i] += x;
    }

    void rm_kth(int k) {
        int l=1, r=MAXN-1;
        while(r > l) {
            int mid = l + (r-l)/2;
            if(psum(mid) >= k) r = mid;
            else l = mid+1;
        }
        update(r,-1);
    }
};

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();

    int n, q; cin >> n >> q;
    int a[n];
    FOR(i,0,n) cin >> a[i];

    int f[MAXN]; memset(f, 0, sizeof(f));
    FOR(i,0,n) f[a[i]]++;

    fenwic_tree ft; ft.init();
    ft.build(f);

    while(q--) {
        int query; cin >> query;
        if(query > 0) ft.update(query, 1);
        else ft.rm_kth(query * -1);
    }  

    int ans=0;

    FOR(i,1,MAXN) if(ft.sum(i,i) > 0) 
        ans = i;
    
    cout << ans << "\n";

    return 0;
}

