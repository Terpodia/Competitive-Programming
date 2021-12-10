#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct segment_tree {
    vector<int> AND;
    
    segment_tree(int n) {
        AND = vector<int>(4*n);
    }

    void build(vector<int>& v, int lx, int rx, int i) {
        if(lx == rx) AND[i] = v[lx]; 
        else {
            int m = (lx+rx)/2;
            build(v, lx, m, i*2);
            build(v, m+1, rx, i*2+1);
            AND[i] = AND[i*2] & AND[i*2+1];
        }
    }

    void build(vector<int>& v) {
        build(v, 0, (int)(v.size())-1, 1);
    }

    int calc(int l, int r, int lx, int rx, int i) {
        if(lx >= l && rx <= r) return AND[i]; 
        else if(lx > r || rx < l) return (1<<30) - 1;
        int m = (lx+rx)/2;

        return calc(l, r, lx, m, i*2) & calc(l, r, m+1, rx, i*2+1);
    }

    int calc(int l, int r) {
        return calc(l, r, 0, (int)(AND.size())/4 - 1, 1);
    }
};

struct event {
    int id, pos, val;
    bool operator<(const event& e) const {
        return pos < e.pos;
    }
};

void upd(vector<int>& d, int x, int flag) {
    int i=0;
    while(x > 0) {
        if(x&1) d[i] += 1*flag;
        x >>= 1;
        i++;
    }
}

int convert(vector<int>& d) {
    int ans=0;
    for(int i=0; i<30; i++) {
        if(d[i] > 0) ans |= (1<<i);
    }
    return ans;
}

int main() {
    int n, m; scanf("%d%d",&n,&m); 
    int b[m][3];
    vector<event> e;

    for(int i=0; i<m; i++) {
        int l,r,q; scanf("%d%d%d",&l,&r,&q);
        l--, r--;

        e.push_back({1,l,q});
        e.push_back({-1,r+1,q});
        b[i][0] = l, b[i][1] = r, b[i][2] = q;
    }
    
    sort(e.begin(), e.end());
    vector<int> d(30, 0);
    int j=0;

    vector<int> a(n);
    
    for(int i=0; i<n; i++) {
        while(j<(int)e.size() && e[j].pos == i) {
            upd(d, e[j].val, e[j].id);
            j++;
        } 
        
        a[i] = convert(d);
    }

    bool can = true;

    segment_tree st(n);
    st.build(a);

    for(int i=0; i<m; i++) {
        can &= (st.calc(b[i][0], b[i][1]) == b[i][2]);
    }

    if(can) {
        puts("YES");
        for(int i=0; i<n; i++) 
            printf("%d%c",a[i]," \n"[i==n-1]);
    }

    else puts("NO");

    return 0;
}

