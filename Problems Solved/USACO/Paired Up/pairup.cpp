#include <fstream>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll,ll> ii;

const int MAXN = 1e5;

int N; ii c[MAXN];

bool comp(ii a, ii b){
    if(a.y != b.y) return a.y < b.y;
    return a.x > b.x;
}

ll solve(){
    sort(c, c+N, comp);

    int a=0, b=N-1; 
    ll ret=0;
    while(a <= b){
        if(a == b){
            ret = max(ret, c[a].y*2);
            break;
        } 

        else{
            ll m = min(c[a].x, c[b].x);
            ret = max(ret, c[a].y + c[b].y);
            c[a].x -= m; c[b].x -= m;
            if(c[a].x == 0) a++;
            if(c[b].x == 0) b--;
        } 
    } 

    return ret;
}

int main(){
    ifstream fin; ofstream fout;
    fin.open("pairup.in"); 
    fout.open("pairup.out");
    
    fin >> N;
    for(int i=0; i<N; i++)
        fin >> c[i].x >> c[i].y;

    fout << solve() << "\n";

    fin.close(); fout.close();
    return 0;
}
