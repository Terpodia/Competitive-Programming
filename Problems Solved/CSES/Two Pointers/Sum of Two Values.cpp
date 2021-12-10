#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2 * 1e5;
pair<int,int> A[MAXN];
int N, X;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    bool flag = false;
    int a = 0, b = N-1;

    sort(A, A+N);
    while(a != b){
        int sum = A[a].first + A[b].first;
        if(sum == X){
            flag = true;
            break;
        }
        else if(sum > X) b--;
        else a++;
    }

    if(flag) cout << A[a].second+1 << " " << A[b].second+1 << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main(){
    fastIO();
    cin >> N >> X;  
    for(int i=0; i<N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }

    solve();

    return 0;
}
