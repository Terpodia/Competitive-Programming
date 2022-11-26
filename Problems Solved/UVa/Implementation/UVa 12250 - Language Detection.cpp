#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	char s[20];
	unordered_map<string, string> ump;
	ump["HELLO"] = "ENGLISH";
	ump["HOLA"] = "SPANISH";
	ump["HALLO"] = "GERMAN";
	ump["BONJOUR"] = "FRENCH";
	ump["CIAO"] = "ITALIAN";
	ump["ZDRAVSTVUJTE"] = "RUSSIAN";
	
	int tc=1;
	
	while(scanf("%s",s) != EOF && s[0] != '#'){
		string a(s);
		printf("Case %d: ", tc++);
		if(ump.find(a) != ump.end()) printf("%s\n", ump[a].c_str());
		else puts("UNKNOWN");
	}
	return 0;
}
