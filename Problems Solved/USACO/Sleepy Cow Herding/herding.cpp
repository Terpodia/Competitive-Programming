#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
    ifstream fin("herding.in");
    ofstream fout("herding.out");

    int cows[3]; fin >> cows[0] >> cows[1] >> cows[2];
    sort(cows, cows+3);

    int hi = -1e9, lo = 1e9;
    if(cows[2] - cows[1] == 1 && cows[1] - cows[0] == 1) lo = hi = 0;

    else{
        if(cows[1] > cows[0]+1){
            if(cows[1] == cows[0]+2) lo = 1;
            else lo = 2;
            hi = max(hi, cows[1] - cows[0] - 1);
        }
        if(cows[1] < cows[2]-1){
            if(cows[1] == cows[2]-2) lo = min(lo, 1);
            else lo = min(lo, 2);
            hi = max(hi, cows[2] - 1 - cows[1]);
        }
    }

    fout << lo << "\n" << hi << "\n";

    return 0;
}
