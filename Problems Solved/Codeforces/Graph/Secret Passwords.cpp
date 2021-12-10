#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5;

int n; string s[MAXN];

vector<int> G[MAXN + 26];
bool vis[MAXN+26];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int DFS(int u) {
    vis[u] = true;
    int cnt=1;

    for(int v : G[u])
        if(!vis[v]) cnt += DFS(v);

    return cnt;
}

int main() {
    fastIO();
    cin >> n;
    for(int i=0; i<n; i++) cin >> s[i];

    for(int i=0; i<n; i++) {
        for(char c : s[i]) {
            G[c-'a'].push_back(i+26);
            G[i+26].push_back(c-'a'); 
        }
    }

    int ans=0;

    for(int i=0; i<26; i++) {
        if(!vis[i]) {
            if(DFS(i) > 1) ans++;      
        }
    }

    printf("%d\n", ans);

    return 0;
}
