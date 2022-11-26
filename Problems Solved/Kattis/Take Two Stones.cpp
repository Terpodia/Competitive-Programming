#include <cstdio>
int aux;

int main() {
  int N;
  aux = scanf("%d", &N);
  printf("%s\n", (N % 2 == 0) ? "Bob" : "Alice");

  return 0;
}
