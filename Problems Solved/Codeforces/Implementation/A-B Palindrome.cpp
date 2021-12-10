#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(false); }

int main(){
    fastIO();
    int t; cin >> t;

    while(t--){
        int a, b; string s;
        cin >> a >> b >> s;

        int cnt0=0, cnt1=0;

        for(char c : s){
            if(c=='0') cnt0++;
            else if(c=='1') cnt1++;
        }

        bool can = true;

        int p1 = 0, p2 = sz(s)-1;

        while(p1 < p2){
            if(s[p1] == '?' && s[p2] == '?') { p1++; p2--; continue; } 
            if(s[p1] == s[p2]) { p1++; p2--; continue; }

            if(s[p1] != '?' && s[p2] != '?') { can = false; break; }

            if(s[p1] != '?'){
                s[p2] = s[p1];
                (s[p1]=='0')? cnt0++ : cnt1++;
            }

            else{
                s[p1] = s[p2];
                (s[p2]=='0')? cnt0++ : cnt1++;
            }

            p1++; p2--;
        }

        p1 = 0, p2 = sz(s)-1;

        while(p1 <= p2){
            if(!can) break;

            if(p1 == p2 && s[p1] == '?'){
                if(cnt0+1 <= a) { cnt0++; s[p1] = '0'; } 
                else { cnt1++; s[p1] = '1'; }
            }

            if(s[p1] == '?' && s[p2] == '?'){
                if(cnt0+2 <= a) { s[p1] = s[p2] = '0'; cnt0 += 2; }
                else { s[p1] = s[p2] = '1'; cnt1 += 2; }
            }

            p1++; p2--;
        }

        if(can && cnt0 == a && cnt1 == b) cout << s << "\n";
        else cout << "-1\n";
    }


    return 0;
}
