#include <iostream>
using namespace std;

const int MAXN = 1e5;

int b[MAXN];

void kmpProcess(string P) {
  int i = 0, j = -1;
  b[0] = -1;
  int m = (int)P.size();
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++, j++;
    b[i] = j;
  }
}

void kmpSearch(string T, string P) {
  int i = 0, j = 0;
  int n = (int)T.size(), m = (int)P.size();
  while (i < n) {
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++, j++;
    if (j == m) {
      printf("P has been found at index %d\n", i - j);
      j = b[j];
    }
  }
}

int main() {
  char T[MAXN], P[MAXN];
  scanf("%[^\n]", T);
  getchar();
  scanf("%[^\n]", P);
  getchar();

  kmpProcess(P);
  kmpSearch(T, P);

  return 0;
}
