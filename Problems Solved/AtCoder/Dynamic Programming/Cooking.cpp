#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ii = pair<int,int>;

const int MAXN = 100;

map<pair<int, ii>, int> dp;

int N, T[MAXN];

int solve(int i, int A, int B) {
    if(i == N) return max(A, B); 
    if(dp.find({i, {A, B}}) != dp.end()) return dp[{i, {A, B}}];

    return dp[{i, {A, B}}] = min(solve(i+1, A+T[i], B), solve(i+1, A, B+T[i]));
}

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",T+i);

    printf("%d\n", solve(0, 0, 0));

    return 0;
}
