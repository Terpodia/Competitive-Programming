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

const ll  MOD = 1e9+7;
#define sz(x) (int)x.size()

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

ll binpow(ll a, ll b, ll p){
    int ret = 1;
    while(b > 0){
        if(b&1) ret = (ret * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return ret;
}

void tc(){
	int t; cin >> t;
	while(t--){
        ll a, b, c; cin >> a >> b >> c;
        ll r = binpow(b, c, MOD-1);
        cout << binpow(a, r, MOD) << endl; 
	}
}

int main(){
    setIO(); tc();

	return 0;
}
