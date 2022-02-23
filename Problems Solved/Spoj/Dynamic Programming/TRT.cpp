#include <iostream>
#include <algorithm>
 
using namespace std;
 
long table[2010][2010];
 
long maximum(long a, long left_pointer, long right_pointer, long treats[]) {
 
  if (right_pointer == left_pointer) {
    return table[left_pointer][right_pointer] = treats[right_pointer] * a;
  }
 
  if (table[left_pointer][right_pointer] != 0) {
    return table[left_pointer][right_pointer];
  }
 
  return table[left_pointer][right_pointer] =
             max(treats[left_pointer] * a +
                     maximum(a + 1, left_pointer + 1, right_pointer, treats),
                 treats[right_pointer] * a +
                     maximum(a + 1, left_pointer, right_pointer - 1, treats));
}
 
int main() {
 
  long N;
  cin >> N;
 
  long treats[N];
 
  for (int i = 0; i < N; i++) {
    cin >> treats[i];
  }
 
  cout << maximum(1, 0, N - 1, treats) << endl;
 
  return 0;
} 

