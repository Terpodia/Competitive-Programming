/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

#define endl "\n"
#define sz(x) (int)x.size()
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define deb(x) cout << #x << " " << x << endl;
#define pb push_back
#define f first
#define s second
#define mp make_pair

int N, K, a[10][20];

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool consistent(int x, int y){
    forn(i, 0, K){
        bool flag = false;
        forn(j, 0, N){
            if(a[i][j] == x) flag = true;
            if(a[i][j] == y && !flag) return false;
        }
    }

    return true;
}

int main(){
    setIO("gymnastics");
    cin >> K >> N;
    
    forn(i, 0, K) forn(j, 0, N) cin >> a[i][j];

    int ans = 0;

    forn(i, 1, N+1)
        forn(j, i+1, N+1)
            if(consistent(i, j) || consistent(j, i)) ans++;

    cout << ans << endl;

	return 0;
}
