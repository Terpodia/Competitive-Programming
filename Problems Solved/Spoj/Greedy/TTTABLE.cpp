#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct trip{
    int start;
    int end;
    int id;
};

struct train{
    int start;
    int cnt;
    int station;
};

int T, NA, NB;
const int MAXN = 300;
trip trips[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

bool cmp(trip a, trip b){
    if(a.start != b.start) return a.start < b.start;
    return a.end < b.end;
}

void solve(){
    int n = NA + NB, ans1 = 0, ans2 = 0;
    vector<train> trains;

    sort(trips, trips+n, cmp);

    int cnt = 0;
    for(int i = 0; i <= 1440; i++){
        if(cnt == n) break;       
        
        while(trips[cnt].start == i && cnt < n){
            int selectedId = -1;
            for(int j = 0; j < (int)trains.size(); j++){
                if(i >= trains[j].start && trips[cnt].id == trains[j].station && trains[j].cnt == 0){
                    selectedId = j;
                    break;
                }           
            }
            if(selectedId == -1){
                if(trips[cnt].id == 0) ans1++;     
                else ans2++;

                trains.push_back({trips[cnt].end, T, 1 - trips[cnt].id});
            }

            else{
                trains[selectedId].start = trips[cnt].end;
                trains[selectedId].cnt = T;
                trains[selectedId].station = 1 - trips[cnt].id;
            }
            cnt++;
        }
        for(int j = 0; j < (int)trains.size(); j++){
            if(trains[j].cnt > 0 && trains[j].start <= i)
                trains[j].cnt--;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
}

int main(){
    fastIO();
    int N; cin >> N;
    int testCase = 1;

    while(N--){
        cin >> T >> NA >> NB;
        for(int i = 0; i < NA; i++){
            int t1, t2;
            char a;

            cin >> t1 >> a >> t2;
            t1 *= 60;
            t2 += t1;
            trips[i].start = t2;
            
            cin >> t1 >> a >> t2;
            t1 *= 60;
            t2 += t1;
            trips[i].end = t2;
            trips[i].id = 0;
        }
        
        for(int i = 0; i < NB; i++){
            int t1, t2;
            char a;

            cin >> t1 >> a >> t2;
            t1 *= 60;
            t2 += t1;
            trips[NA+i].start = t2;
            
            cin >> t1 >> a >> t2;
            t1 *= 60;
            t2 += t1;
            trips[NA+i].end = t2;
            trips[NA+i].id = 1;
        }
        cout << "Case #" << testCase << ": ";
        solve();
        testCase++;
    }


    return 0;
}
