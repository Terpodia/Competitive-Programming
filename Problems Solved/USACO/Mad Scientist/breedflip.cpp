#include <iostream>
#include <fstream>
using namespace std;

int N;
string s1, s2;

int solve(){
    int ret=0;
    
    for(int i=0; i<N; i++){
        if(s1[i] == s2[i]) continue; 
        else if(i==N-1 || s1[i+1] == s2[i+1]) ret++;
    }

    return ret;
}

int main(){
    ifstream fin; ofstream fout;
    fin.open("breedflip.in"); fout.open("breedflip.out");

    fin >> N >> s1 >> s2;    
    fout << solve() << "\n";

    fin.close(); fout.close();
    return 0;
}
