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

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for(int i = (x); i >= (int)(n); i-=a)
#define forsn(i, x, n, a) for(int i = (x); i < (int)(n); i+=a)
#define rforn(i, x, n) for(int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for(int i = (x); i < (int)(n); i++)
#define deb(x) cout << #x << " " << x << endl;
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define endl "\n"
#define s second
#define f first

const ll INF = 1e18, MOD = 1e9+7;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void tc(){
	int t; cin >> t;
	while(t--){
        int n; string s; cin >> n >> s;
        vector<bool> used(n, false); queue<int> ts;
        int cntT=0, cntM=0;
        forn(i, 0, n) (s[i] == 'M')? cntM++ : cntT++;

        if(cntM != n/3 || cntT != n/3 * 2) cout << "NO\n";

        else{
            bool can = true;
            forn(i, 0, n){
                if(s[i] == 'T') ts.push(i);
                else{
                    if(ts.empty()) { can = false; break; }
                    else { used[ts.front()] = true; ts.pop(); cntT--;}  
                } 
            }

            while(!ts.empty()) ts.pop();

            if(cntT != n/3) can = false;

            rforn(i, n-1, 0){
                if(s[i] == 'T' && !used[i]) ts.push(i);

                else if(s[i] == 'M'){
                    if(ts.empty()) { can = false; break; }
                    else { used[ts.front()] = true; ts.pop(); cntT--;}  
                } 
            }
            
            if(cntT != 0) can = false;

            if(can) cout << "YES\n";
            else cout << "NO\n";
        }
	}
}

int main(){
    setIO();
    tc();

	return 0;
}
