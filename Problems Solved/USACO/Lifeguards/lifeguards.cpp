#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct lifeguard{
    ll l, r; 
    int id;
};

const int MAXN = 1e5;
int N;
lifeguard a[MAXN];

ll initAns(pair<ll,ll> p[]){
    ll ret = 0, cnt = 0, pos;
    vector<bool> check(N, false);

    for(int i = 0; i < 2*N; i++){
        if(cnt == 0) pos = p[i].first;

        if(!check[p[i].second]){
            check[p[i].second] = true;
            cnt++;
        }
        else{
            cnt--;
            if(cnt == 0){
                ret += p[i].first - pos;
            }
        }
    } 
    return ret;
}

ll solve(){
    pair<ll,ll> p[N*2];
    
    for(int i=0; i<N; i++){
        p[i].first = a[i].l;
        p[i].second = a[i].id;
    }
    
    for(int i=N; i<N*2; i++){
        p[i].first = a[i-N].r;
        p[i].second = a[i-N].id;
    }

    sort(p, p+2*N); 
    ll ans = 1e9, cnt1 = 1, cnt2 = 0; 
    ll pos = p[0].first;
    
    vector<bool> check(N, false); 
    check[p[0].second] = true;

    for(int i=1; i<2*N; i++){
        if(cnt1 == 1){
            cnt2 += p[i].first - pos;
        }

        if(!check[p[i].second]){
            cnt1++;
            check[p[i].second] = true;
        }
        else{
            cnt1--;
            ans = min(ans, cnt2);
            cnt2 = 0;
        }
        pos = p[i].first;
    }

    return initAns(p) - ans;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("lifeguards.in");
    fout.open("lifeguards.out");
    
    fin >> N;
    for(int i=0; i<N; i++){
        fin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    
    fout << solve() << "\n";

    fin.close();
    fout.close();

    return 0;
}
