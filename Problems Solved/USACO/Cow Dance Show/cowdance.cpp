#include <fstream>
using namespace std;

const int MAXN = 1e4;
int N; 
long long cow[MAXN], tmax;

bool f(long long x){
    long long s = 0;
    s += cow[0];
    for(int i=x+1; i<N; i++)
        s += cow[i];

    return s <= tmax;
}

int solve(){
    int lo = -1, hi = N, mid;
    while(hi - lo > 1){
        mid = (hi+lo)/2;
        if(f(mid)) hi = mid;        
        else lo = mid;
    }
    return hi;
}

int main(){
    ifstream fin; ofstream fout;
    fin.open("cowdance.in"); fout.open("cowdance.out");

    fin >> N >> tmax; 
    for(int i=0; i<N; i++) fin >> cow[i];

    fout << solve()+1 << "\n";

    fin.close(); fout.close();
    return 0;
}