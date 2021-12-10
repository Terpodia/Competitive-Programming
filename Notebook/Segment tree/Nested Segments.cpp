#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)

struct segTree
{
    vector<int> nodes;

    void init(int n){nodes.resize(n*4);}

    int sum(int l, int r, int lx, int rx, int x)
    {
        if(lx > r || rx < l) return 0;
        if(lx >= l && rx <= r) return nodes[x];

        int m = (lx + rx) / 2;
        return sum(l, r, lx, m, x*2) + sum(l, r, m+1, rx, x*2+1);
    }
    
    void update(int pos, int lx, int rx, int x)
    {
        if(lx == rx) nodes[x] = 1;
        else
        {
            int m = (lx + rx) / 2;
            if(pos <= m) update(pos, lx, m, x*2);
            else update(pos, m+1, rx, x*2+1);

            nodes[x] = nodes[x*2] + nodes[x*2+1];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    segTree st; unordered_map<int, int> mp;
    int n; cin >> n; n *= 2;
    st.init(n);
    int segments[n], array[n/2];
    forr(i, 0, n) cin >> segments[i];

    forr(i, 0, n)
    {
        if(mp.find(segments[i]) != mp.end())
        {
            int answer = st.sum(mp[segments[i]], i, 0, n-1, 1);
            array[segments[i]-1] = answer;
            st.update(mp[segments[i]], 0, n-1, 1);
        }
        else mp[segments[i]] = i;
    }

    forr(i, 0, n/2) cout << array[i] << " ";

    cout << "\n";
    return 0;
}