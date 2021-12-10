#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
using namespace std;
using pi = pair<int,int>;

#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define mp make_pair
#define s second
#define f first

void setIO() { cin.tie(0)->sync_with_stdio(0); }

const int MAXN = 1e3, xd[] = { 1, -1, 0, 0 }, yd[] = { 0, 0, 1, -1 };
const int INF = 1e9;

int n, m;
char a[MAXN][MAXN];

bool can(int i, int j) {
    return (i<n && j<m && i>=0 && j>=0 && a[i][j] != '*');
}

void solve(pi s, pi t) {
    deque<tuple<int, int, int, int>> Q;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(5, INF)));

    Q.push_front(make_tuple(s.f, s.s, 4, -1));
    dist[s.f][s.s][4] = dist[s.f][s.s][3] = dist[s.f][s.s][2] = dist[s.f][s.s][1] = dist[s.f][s.s][0] = -1;

    while(!Q.empty()) {
        tuple<int,int,int,int> query = Q.front(); Q.pop_front();

        auto& [i,j,dir,cnt] = query;

        if(cnt != dist[i][j][dir]) continue;

        forn(_, 0, 4) {
            int x=i+xd[_], y=j+yd[_];
            if(!can(x,y)) continue;

            int z = (_==dir)? cnt : cnt+1;

            if(z < dist[x][y][_]) {
                dist[x][y][_] = z;
                (z == cnt)? Q.push_front(make_tuple(x, y, _, z)) : Q.push_back(make_tuple(x, y, _, z));
            }
        }
    }
    
    (dist[t.f][t.s][0] < 3 || dist[t.f][t.s][1] < 3 || dist[t.f][t.s][2] < 3 || dist[t.f][t.s][3] < 3)? cout << "YES\n" : cout << "NO\n";
}

int main() {
    setIO();
    cin >> n >> m;
    forn(i, 0, n) forn(j, 0, m) cin >> a[i][j];

    pi s, t;
    forn(i, 0, n) forn(j, 0, m) {
        if(a[i][j] == 'S') s = mp(i, j);
        else if(a[i][j] == 'T') t = mp(i, j);
    }

    solve(s, t);

	return 0;
}

