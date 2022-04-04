#include <iostream>
#include <vector>
using namespace std;

#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)
typedef long long ll;
typedef vector<ll> vi;

struct segTree
{
    vi nodes;
    void init(int n){nodes.resize(n*4);}

    void update(int pos, int val, int lx, int rx, int x)
    {
        if(lx == rx) nodes[x] += val;
        else
        {
            int m = (lx + rx) / 2;
            if(pos <= m) update(pos, val, lx, m, x*2);
            else update(pos, val, m+1, rx, x*2+1);
            nodes[x] = nodes[x*2] + nodes[x*2+1];
        }
    }
    
    ll sum(int l, int r, int lx, int rx, int x)
    {
        if(lx > r || rx < l) return 0;
        if(lx >= l && rx <= r) return nodes[x];
        
        int m = (lx + rx) / 2;
        return sum(l, r, lx, m, x*2) + sum(l, r, m+1, rx, x*2+1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    segTree st;
    int n, m, q, l, r, p, v;

    cin >> n >> m; st.init(n);

    forr(i, 0, m)
    {
        cin >> q;
        if(q == 1)
        {
            cin >> l >> r >> v;
            st.update(l, v, 0, n-1, 1);
            if(r < n) st.update(r, -v, 0, n-1, 1);
        }
        else
        {
            cin >> p;
            cout << st.sum(0, p, 0, n-1, 1) << "\n";
        }
    }

    return 0;
}