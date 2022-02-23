#include <iostream>
#include <map>
 
using namespace std;
 
map<long, long> diccionary;
map<long, long>::iterator itre;
 
long maximum_number_coins(long itr, long coins[]) {
 
  if (itr < 0) {
    return 0;
  }
 
  else if (itr == 0) {
    return coins[itr];
  }
 
  itre = diccionary.find(itr);
 
  if (itre != diccionary.end()) {
    return itre->second;
  }
 
  diccionary.insert(
      make_pair(itr, max(coins[itr] + maximum_number_coins(itr - 2, coins),
                         coins[itr] + maximum_number_coins(itr - 3, coins))));
  itre = diccionary.find(itr);
  return itre->second;
}
 
int main() {
  long number_test_cases, N;
  cin >> number_test_cases;
 
  for (int i = 1; i <= number_test_cases; i++) {
    cin >> N;
    long coins[N];
 
    for (int j = 0; j < N; j++) {
      cin >> coins[j];
    }
    cout << "Case " << i << ": "
         << max(maximum_number_coins(N - 2, coins),
                maximum_number_coins(N - 1, coins))
         << endl;
    diccionary.clear();
  }
 
  return 0;
} 

