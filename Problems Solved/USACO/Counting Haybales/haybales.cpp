#include <fstream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, Q;

int bs(int a[], int x){
    int lo = -1, hi = N, mid;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        if(a[mid] >= x) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main(){
    ifstream fin;
    ofstream fout;
    fin.open("haybales.in");
    fout.open("haybales.out");

    fin >> N >> Q;
    int a[N];
    for(int i = 0; i < N; i++) fin >> a[i];
    sort(a, a+N);

    while(Q--){
        int l, r; fin >> l >> r;        
        int m1 = bs(a, l), m2 = bs(a, r);
        if(m2 == N) m2--;
        else if(a[m2] > r) m2--;
        if(m1 == N) fout << "0\n";
        else fout << m2+1-m1 << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
