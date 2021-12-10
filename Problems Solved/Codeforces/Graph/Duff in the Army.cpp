#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define sz(x) (int)x.size()

const int MAXN = 1e5, MAXLOG = 17;

vector<int> G[MAXN];
vector<int> people[MAXN];

int anc[MAXN][MAXLOG];
vector<int> anc_people[MAXN][MAXLOG];
int H[MAXN];

vector<int> merge(vector<int>& v1, vector<int>& v2) {
    vector<int> ret = { };

    auto i = v1.begin(), j = v2.begin();

    while((i != v1.end() || j != v2.end()) && sz(ret) <= 10) {
        if(i == v1.end()) { 
            if(find(ret.begin(), ret.end(), *j) == ret.end()) 
                ret.push_back(*j); 
            j++;
        }

        else if(j == v2.end()) {
            if(find(ret.begin(), ret.end(), *i) == ret.end()) 
                ret.push_back(*i); 
            i++;
        }

        else {
            auto it1 = find(ret.begin(), ret.end(), *j);
            auto it2 = find(ret.begin(), ret.end(), *i);

            if(it1 != ret.end() || it2 != ret.end()) {
                if(it1 != ret.end()) j++;
                if(it2 != ret.end()) i++;
                continue;
            }

            if(*i < *j) ret.push_back(*i), i++;
            else ret.push_back(*j), j++;
        }
    }

    return ret;
}

void DFS(int u, int p=-1, vector<int> s = vector<int> { }) {
    if(p != -1) H[u] = H[p]+1;
    anc[u][0] = p;
    anc_people[u][0] = merge(s, people[u]);

    for(int i=1; i<MAXLOG; i++) {
        if(anc[u][i-1] != -1) 
            anc[u][i] = anc[anc[u][i-1]][i-1],
            anc_people[u][i] = merge(anc_people[u][i-1], anc_people[anc[u][i-1]][i-1]);
    }

    for(int v : G[u]) if(v != p) 
        DFS(v, u, people[u]);
}

void print(vector<int>& s, int a) {
    int j=0, k=min(sz(s),a);
    printf("%d ", k);
    if(k == 0) puts("");

    for(auto it = s.begin(); it != s.end() && j < k; it++, j++)
        printf("%d%c", *it, " \n"[j==k-1]);
}

void solve(int u, int v, int a) {
    if(u == v) { print(people[u], a); return; }

    if(H[v] < H[u]) swap(v, u);

    vector<int> ans;

    for(int i=MAXLOG-1; i>-1; i--) {
        if(anc[v][i] != -1 && H[anc[v][i]] >= H[u])
            ans = merge(ans, anc_people[v][i]), v = anc[v][i];
    }

    if(u == v) { print(ans, a); return; } 

    for(int i=MAXLOG-1; i>-1; i--) {
        if(anc[u][i] != -1 && anc[u][i] != anc[v][i])
            ans = merge(ans, anc_people[u][i]), ans = merge(ans, anc_people[v][i]),
            u = anc[u][i], v = anc[v][i];
    }

    ans = merge(ans, anc_people[u][0]), ans = merge(ans, anc_people[v][0]);

    print(ans, a);
}

int main() {
    int n, m, q; scanf("%d%d%d",&n,&m,&q);
    
    for(int i=0; i<n-1; i++) {
        int u, v; scanf("%d%d",&u,&v);
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=0; i<m; i++) {
        int c; scanf("%d",&c);
        c--; people[c].push_back(i+1);
        if(sz(people[c]) > 10) 
            people[c].erase(max_element(people[c].begin(), people[c].end()));
    }

    for(int i=0; i<n; i++) 
        sort(people[i].begin(), people[i].end());

    memset(anc, -1, sizeof(anc));
    DFS(0);

    while(q--) {
        int u, v, a; scanf("%d%d%d", &u, &v, &a);
        u--, v--;
        solve(u, v, a);
    }

    return 0;
}

