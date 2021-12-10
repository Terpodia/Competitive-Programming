#include <iostream>
#include <set>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(false); }

int n; string s;

void construct_set(set<string>& s1, set<string>& s2, set<string>& s3) {
    for(int i=0; i<n; i++) {
        string sub_str; sub_str.push_back(s[i]);
        s1.insert(sub_str);
    }

    for(int i=0; i<n-1; i++) {
        string sub_str;
        sub_str.push_back(s[i]);
        sub_str.push_back(s[i+1]);

        s2.insert(sub_str);
    }

    for(int i=0; i<n-2; i++) {
        string sub_str;
        sub_str.push_back(s[i]);
        sub_str.push_back(s[i+1]);
        sub_str.push_back(s[i+2]);

        s3.insert(sub_str);
    }
}

void solve() {
    set<string> s1, s2, s3;
    construct_set(s1, s2, s3);

    for(int i=0; i<26; i++) {
        string a; a.push_back((char)i+97);
        if(s1.find(a) == s1.end()) { cout << a << "\n"; return; }
    }

    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++) {
            string a; 
            a.push_back((char)i+97);
            a.push_back((char)j+97);
            if(s2.find(a) == s2.end()) { cout << a << "\n"; return; }
        }
    
    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
            for(int z=0; z<26; z++) {
                string a; 
                a.push_back((char)i+97);
                a.push_back((char)j+97);
                a.push_back((char)z+97);
                if(s3.find(a) == s3.end()) { cout << a << "\n"; return; }
            }
}

int main() {
    fastIO();

    int t; cin >> t;
    while(t--) {
        cin >> n >> s;
        solve();
    }

    return 0;
}
