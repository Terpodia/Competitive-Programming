#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

int main() {
    int N; scanf("%d",&N);
    vector<pair<int,int>> a(1<<N);

    for(int i=0; i<(1<<N); i++) {
        scanf("%d",&a[i].first);
        a[i].second = i;
    }

    int ans;

    for(int i=1; i<=N; i++) {
        vector<pair<int,int>> aux;

        for(int j=0; j<sz(a); j++)
            if(a[j].first != -1) aux.push_back(a[j]);

        a = aux;

        for(int j=1; j<=(1<<(N-i)); j++) {
            if(i==N) {
                if(a[2*j-1].first > a[2*j-2].first) ans = a[2*j-2].second + 1; 
                else ans = a[2*j-1].second + 1;
            }

            if(a[2*j-1].first > a[2*j-2].first) a[2*j-2].first = -1;

            else a[2*j-1].first = -1;
        }
    }

    printf("%d\n", ans);

    return 0;

}
