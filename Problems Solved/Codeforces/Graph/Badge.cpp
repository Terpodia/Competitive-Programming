#include <iostream>
using namespace std;

const int MAXN = 1000;
int n, p[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int floyd(int x){
    int a = p[x], b = p[p[x]], ret = 0;
    while(a != b){
        a = p[a];
        b = p[p[b]];
    }

    a = x;

    while(a != b){
        a = p[a];
        b = p[b];
    }
    
    ret = a;
    return ret+1;
}

int main(){
    fastIO();
    cin >> n; for(int i=0; i<n; i++){cin >> p[i]; p[i]--;}
    for(int i=0; i<n; i++) cout << floyd(i) << " ";
    cout << "\n";

    return 0;
}
