#include <iostream>
#include <vector>
using namespace std;
using pi = pair<int,int>;

#define f first
#define s second

const int MAXN = 1e3;

int n, a[MAXN];

void solve(){
    int k=(n/2) * 6; 
    vector<pair<int, pi>> operations;

    for(int i=0; i<n; i+=2){
        for(int j=0; j<6; j++){
            if(j%2==0) operations.push_back({2, {i+1, i+2}});
            else operations.push_back({1, {i+1, i+2}});
        }
    }

    printf("%d\n", k);
    for(int i=0; i<k; i++)
        printf("%d %d %d\n", operations[i].f, operations[i].s.f, operations[i].s.s); 
}

int main(){
    int t; scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i);

        solve();
    }

    return 0;
}
