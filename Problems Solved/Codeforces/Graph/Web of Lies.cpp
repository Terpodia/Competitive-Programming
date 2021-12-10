#include <cstdio>
#include <set>
#include <vector>
using namespace std;


int main() {
    int n, m; scanf("%d%d",&n,&m);

    vector<set<int>> friends(n);
    vector<bool> ok(n, true);

    for(int i=0; i<m; i++) {
        int u, v; scanf("%d%d",&u,&v);
        friends[u-1].insert(v-1);
        friends[v-1].insert(u-1);
    }

    int ans=0;

    for(int i=0; i<n; i++) {
        if(friends[i].empty() || *friends[i].rbegin() < i) ans++;
        else ok[i] = false; 
    }
    
    int q; scanf("%d",&q);

    while(q--) {
        int t; scanf("%d", &t);

        if(t == 1) {
            int u, v; scanf("%d%d",&u,&v);
            u--, v--;
            friends[u].insert(v);
            friends[v].insert(u);

            if(*friends[u].rbegin() > u && ok[u]) ok[u] = false, ans--; 
            if(*friends[v].rbegin() > v && ok[v]) ok[v] = false, ans--; 
        }

        else if(t == 2) {
            int u, v; scanf("%d%d",&u,&v);
            u--, v--;
            friends[u].erase(v);
            friends[v].erase(u);

            if((friends[u].empty() || *friends[u].rbegin() < u) && !ok[u]) ok[u] = true, ans++; 
            if((friends[v].empty() || *friends[v].rbegin() < v) && !ok[v]) ok[v] = true, ans++;
        }

        else printf("%d\n", ans);
    }

    return 0;
}

