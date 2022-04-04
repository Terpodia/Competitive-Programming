#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)
#define forR(i, x, n) for(int i = (x); i > (int)(n); i--)
 
struct segTree
{
    vector<int> nodes;
    void init(int n)
    {
        nodes.resize(n*4);
    }
 
    void build(int lx, int rx, int x)
    {
        if(lx == rx) nodes[x] = 1;
        else
        {
            int m = (lx + rx) / 2;
            build(lx, m, x*2);
            build(m+1, rx, x*2+1);
            nodes[x] = nodes[x*2] + nodes[x*2+1];
        }
    }
 
    void update(int pos, int lx, int rx, int x)
    {
        if(lx == rx) nodes[x] = 0;
        else
        {
            int m = (lx + rx) / 2;
            if(pos <= m) update(pos, lx, m, x*2);
            else update(pos, m+1, rx, x*2+1);
 
            nodes[x] = nodes[x*2] + nodes[x*2+1];
        }
    }
 
    int find(int k, int lx, int rx, int x)
    {
        if(lx == rx) return lx+1;
        int a = nodes[x*2];
 
        int m = (lx + rx) / 2;
        if(k < a) return find(k, lx, m, x*2);
        return find(k-a, m+1, rx, x*2+1);
    }
};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    segTree st;
    int n, counter = 0;
    stack<int> s;
    cin >> n;
    int a[n];
    st.init(n);
 
    forr(i, 0, n) cin >> a[i];
    st.build(0, n-1, 1);
 
    forR(i, n-1, -1)
    {
        int ans = st.find(n-1-a[i]-counter, 0, n-1, 1);
        s.push(ans);
        st.update(ans-1, 0, n-1, 1);
        counter++;
    }
 
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}