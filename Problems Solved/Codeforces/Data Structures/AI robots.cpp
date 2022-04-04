#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define LSOne(x) (x) & (-x)

const int M = 3e5 + 17;

struct fenwic_tree {
    ll ft[M];

    void init() { memset(ft, 0, sizeof(ft)); }

    ll pref_sum(int i) {
        ll ret=0;
        for(; i > 0; i-=LSOne(i)) ret += ft[i];
        return ret;
    }

    ll rsq(int l, int r) {
        return pref_sum(r) - pref_sum(l-1);
    }

    void upd(int i, int x) {
        for(; i<M; i += LSOne(i)) ft[i] += x;
    }
};

const int MAXN = 1e5;

int N, K;

vector<tuple<int,int,int>> a;

vector<pair<int, vector<tuple<int,int,int>>>> mp;

fenwic_tree ft;

void compress() {
    vector<int> p;
    for(int i=0; i<sz(mp); i++) {
        for(auto& [l,r,x] : mp[i].second) {
            p.push_back(l);
            p.push_back(r);
            p.push_back(x);
        }
    }

    sort(all(p));
    p.resize(distance(p.begin(), unique(all(p)))); 

    for(int i=0; i<sz(mp); i++) {
        for(auto& [l,r,x] : mp[i].second) {
            l = (int)distance(p.begin(), lower_bound(all(p), l));
            r = (int)distance(p.begin(), lower_bound(all(p), r));
            x = (int)distance(p.begin(), lower_bound(all(p), x));        
        }
    }
}

ll solve(int q1, int q2) {
    vector<tuple<int,int,int>> v1, v2;

    for(auto& [l,r,x] : mp[q1].second) v1.push_back({l,r,x});
    for(auto& [l,r,x] : mp[q2].second) v2.push_back({l,r,x});

    vector<pair<int,int>> adds, dels;
    for(auto& [l,r,x] : v2) {
        adds.push_back(make_pair(l, x));
        dels.push_back(make_pair(r, x));
    }

    sort(all(adds)); sort(all(dels));

    int i=0, j=0;
    ll ret=0;

    for(auto& [l,r,x] : v1) {
        while(i < sz(adds) && adds[i].first <= x) ft.upd(adds[i++].second+1, 1); 
        while(j < sz(dels) && dels[j].first < x) ft.upd(dels[j++].second+1, -1);
        ret += ft.rsq((int)l+1, (int)r+1);
    }

    while(i < sz(adds)) ft.upd(adds[i++].second+1, 1); 
    while(j < sz(dels)) ft.upd(dels[j++].second+1, -1);

    return ret;
}

int main() {
    ft.init();
    scanf("%d%d",&N,&K);    
    a = vector<tuple<int,int,int>>(N, {0,0,0});

    for(int i=0; i<N; i++) {
        auto& [x,r,q] = a[i];
        scanf("%d%d%d", &x,&r,&q); 
    } 

    sort(all(a), [](tuple<int,int,int>& x, tuple<int,int,int>& y) {
        return get<2>(x) < get<2>(y);
    });
    
    for(int i=0; i<N;) {
        vector<tuple<int, int, int>> b;
        int q = get<2>(a[i]);

        while(i < N && get<2>(a[i]) == q) {
          b.push_back( { max(get<0>(a[i]) - get<1>(a[i]), 0), get<0>(a[i]) + get<1>(a[i]), get<0>(a[i]) } );
          i++;
        }        

        mp.push_back(make_pair(q, b)); 
    }

    compress();

    for(int i=0; i<sz(mp); i++)
        sort(all(mp[i].second), [](tuple<int,int,int>& x, tuple<int,int,int>& y) {
            return get<2>(x) < get<2>(y);
        });

    ll ans=0;

    for(int i=0; i<sz(mp); i++) {
        for(int j=i; j<sz(mp); j++) {
            int q1 = mp[i].first, q2 = mp[j].first;
            if(q2 - q1 > K) break;
            ans += (q2 == q1)? (solve(i, j) - sz(mp[i].second)) / 2 : solve(i, j);
        }
    }

    printf("%lld\n", ans);

    return 0;
}

