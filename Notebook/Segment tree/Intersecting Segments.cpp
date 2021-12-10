#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)
#define forR(i, x, n) for(int i = (x); i > (n); i--)

struct segTree
{
    vector<int> nodes;
    void init(int n){nodes.resize(n*4);}

    void build(int lx, int rx, int x)
    {
        if(lx == rx) nodes[x] = 0;
        else
        {
            int m = (lx + rx) / 2;
            build(lx, m, x*2);
            build(m+1, rx, x*2+1);
            nodes[x] = nodes[x*2] + nodes[x*2+1];
        }
    }

    void update(int pos, int val, int lx, int rx, int x)
    {
        if(lx == rx) nodes[x] = val;
        else
        {
            int m = (lx + rx) / 2;
            if(pos <= m) update(pos, val, lx, m, x*2);
            else update(pos, val, m+1, rx, x*2+1);

            nodes[x] = nodes[x*2] + nodes[x*2+1];
        }
    }

    int sum(int l, int r, int lx, int rx, int x)
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

    segTree st, in_st;
    unordered_map<int, int> mp1, mp2;
    int n; cin >> n; n *= 2;
    
    st.init(n); st.build(0, n-1, 1);
    in_st.init(n); in_st.build(0, n-1, 1);

    int p[n], inverse_p[n];
    vector<int> ans(n/2, 0);
    forr(i, 0, n)
    {
        cin >> p[i];
        inverse_p[n-1-i] = p[i]; 
    }

    forr(i, 0, n)
    {
        if(mp1.find(p[i]) != mp1.end())
        {
            int aux = mp1[p[i]];
            st.update(aux, 0, 0, n-1, 1);
            ans[p[i]-1] += st.sum(aux, i, 0, n-1, 1);
        }
        else
        {
            mp1[p[i]] = i;
            st.update(i, 1, 0, n-1, 1);
        }

        if(mp2.find(inverse_p[i]) != mp2.end())
        {
            int aux = mp2[inverse_p[i]];
            in_st.update(aux, 0, 0, n-1, 1);
            ans[inverse_p[i]-1] += in_st.sum(aux, i, 0, n-1, 1);
        } 
        else
        {
            mp2[inverse_p[i]] = i;
            in_st.update(i, 1, 0, n-1, 1);
        }
    }

    forr(i, 0, n/2) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}