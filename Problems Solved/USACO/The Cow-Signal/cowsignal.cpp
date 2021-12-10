#include <fstream>
using namespace std;

int N, M, K, row=0;
char a[10][10], ans[100][100];

void amplifySignal(char rowCharacters[]){
    for(int i=0; i<K; i++){
        for(int j=0; j<M*K; j++){
            ans[row][j] = rowCharacters[j];
        } 
        row++;
    }
}

int main(){
    ifstream fin; ofstream fout;
    fin.open("cowsignal.in"); fout.open("cowsignal.out");

    fin >> N >> M >> K;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            fin >> a[i][j];
    
    for(int i=0; i<N; i++){
        char rowCharacters[M*K];
        int z=0;
        for(int j=0; j<M; j++){
            for(int w=0; w<K; w++){
                rowCharacters[z] = a[i][j];
                z++;
            }
        }
        amplifySignal(rowCharacters);
    }

    for(int i=0; i<N*K; i++){
        for(int j=0; j<M*K; j++){
            fout << ans[i][j];
        }
        fout << "\n";
    }

    fin.close(); fout.close();
    return 0;
}
