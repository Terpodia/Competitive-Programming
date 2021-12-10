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
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
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
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define dbg(x) cerr << #x << "=" << x << "\n";
#define line cerr << ".....................................\n"
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define s second
#define f first

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
    cout << fixed << setprecision(15); 
}

int main() {
    setIO();
    int n,cnt=1; cin >> n;
    string s; cin >> s;
    string x;

    forn(i,0,n) {
        x += to_string((((s[i]-'0')+cnt)%2)); 
        if(cnt==1 && x[i] == '1') cnt=0;
    }

    int ans=0;
    forn(i,0,n) if(s[i]!=x[i]) ans++;
    cout << ans << "\n";

	return 0;
}

