#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)

struct DSU {
    vi p, size;

    void init(int n) {
        p = vi(n); size = vi(n,1);
        forn(i,0,n) p[i] = i;
    }
    
    int findSet(int x){
        if(p[x] != x) return p[x] = findSet(p[x]);
        return x;
    }

    void unionSet(int x, int y){
        int rx = findSet(x), ry = findSet(y);
        if(size[rx] < size[ry]) swap(rx, ry);
        p[ry] = rx, size[rx] += size[ry];
    }
};

int main() {
    int N, Q; cin >> N >> Q; // Number of nodes and number of queries

    DSU dsu; dsu.init(N); // Declaring Union-Find DS

    while(Q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 0) dsu.unionSet(u, v); // If t == 0, then union u and v

        else{ // If t == 1
            if(dsu.findSet(u) == dsu.findSet(v)) cout << "1\n"; // Print 1 if u and v are in the same Connected Component
            else cout << "0\n"; // Otherwise print 0
        }
    }

	return 0;
}

