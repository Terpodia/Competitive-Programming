#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

void print(int i, int j) { 
    cout << "? " << i << " " << j << "\n";
    fflush(stdout);
}

int main() {
    int n; cin >> n;
    ll a,b,c;
    print(1, 2); cin >> a;
    print(2, 3); cin >> b;
    print(1, 3); cin >> c;

    ll ans[n]; 
    ans[0] = (a-b+c)/2;
    ans[1] = a-ans[0];
    ans[2] = c-ans[0];

    for(int i=3; i<n; i++) {
        print(i, i+1);
        ll d; cin >> d;
        ans[i] = d - ans[i-1];
    }

    cout << "! ";
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
    fflush(stdout);

    return 0;
}
