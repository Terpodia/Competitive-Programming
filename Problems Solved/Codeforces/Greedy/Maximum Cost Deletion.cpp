#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) {
        int n, a, b; string s;
        cin >> n >> a >> b >> s;

        int x1=(a+b)*n,x2=0,x3=0;

        vector<int> v1, v2;
        int sum1=0, sum2=0;

        int cnt=1;

        for(int i=0; i<n; i++) {
            (s[i] == '1')? sum1++ : sum2++; 

            if(i+1 < n && s[i+1] == s[i]) { cnt++; continue; } 
            (s[i] == '1')? v1.push_back(cnt) : v2.push_back(cnt);
            cnt=1;
        }

        for(int i=0; i<sz(v1); i++) x2 += v1[i] * a + b;
        if(sum2>0) x2 += sum2 * a + b;

        for(int i=0; i<sz(v2); i++) x3 += v2[i] * a + b;
        if(sum1>0) x3 += sum1 * a + b;

        cout << max(x1, max(x2, x3)) << "\n";
    }

    return 0;
}

