#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> pi;

#define sz(x) (int)x.size()

string s; 

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

void solve() {
    vector<pi> v;
    int curr=0;

    for(int i=0; i<sz(s); i++) {
        (s[i] == '+')? curr++ : curr--;
        if(curr < 0) v.push_back(make_pair(i, curr));
    }

    long long res=0; int j=0;

    for(int i=0; true; i++) {
        while(j < sz(v) && abs(v[j].second) <= i) j++;

        if(j == sz(v)) break;
        else res += (long long)v[j].first+1;
    }

    res += sz(s);

    cout << res << "\n";
}

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) { cin >> s; solve(); }

    return 0;
}

