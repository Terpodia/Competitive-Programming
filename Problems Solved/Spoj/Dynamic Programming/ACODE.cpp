#include <string.h>

#include <iostream>
#include <map>

using namespace std;

int suma = 0;
int aux0, aux1, aux2;

map<int, int> diccionary;
map<int, int>::iterator itre;

void count_decodings(string &digits, int itr, int length) {
  if (itr > length - 1) {
    suma += 1;
    return;
  }

  aux0 = digits[itr] - '0';
  aux2 = digits[itr + 1] - '0';
  aux1 = aux0 * 10 + aux2;

  if (itr == length - 1 && aux0 != 0) {
    suma += 1;
    return;
  }

  itre = diccionary.find(itr);
  if (itre != diccionary.end()) {
    suma += itre->second;
  } else if (9 < aux1 && aux1 < 27) {
    if (aux2 != 0) count_decodings(digits, itr + 1, length);
    count_decodings(digits, itr + 2, length);
    diccionary.insert(make_pair(itr, suma));
  } else if (aux0 != 0) {
    count_decodings(digits, itr + 1, length);
    diccionary.insert(make_pair(itr, suma));
  }
  return;
}

int main() {
  string digits;

  do {
    cin >> digits;
    if (digits == "0") break;
    count_decodings(digits, 0, digits.length());
    cout << suma << endl;
    suma = 0;
    diccionary.clear();
  } while (digits != "0");

  return 0;
}
