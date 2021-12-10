#include <stdio.h>
#include <vector>
using namespace std;
int d;

void solve(){
    bool c[30012];
    vector<int> v;
    for(int i = 0; i < 30012; i++)
        c[i] = true;

    c[0] = false;
    c[1] = false;
    
    for(int i = 2; i < 30012; i++){
        if(c[i]){
            for(int j = i*2; j < 30012; j+=i){
                c[j] = false;
            }
            
            v.push_back(i);
        }
    }
    
    long long a1, a2;
    int index = -1;
    for(int i = 0; i <= (int)v.size(); i++){
        if(v[i] - 1 >= d){
            a1 = v[i];
            index = i;
            break;
        }
    }
    
    for(int i = index+1; i <= (int)v.size(); i++){
        if(v[i] - a1 >= d){
            a2 = v[i];
            break;
        }
    }
    printf("%lld\n",a1*a2); 
}

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&d);
        solve();
    }

    return 0;
}
