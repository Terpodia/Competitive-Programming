#include <iostream>
#include <cstring>
 
using namespace std;
 
int table[2000][2000] = {0};
 
int solve(int cards[], int left_pointer, int right_pointer, int turn) {
 
  if (turn % 2 != 0) {
 
    if (left_pointer == right_pointer) {
      return table[left_pointer][right_pointer] = cards[left_pointer];
    }
 
    if (table[left_pointer][right_pointer] != 0) {
      return table[left_pointer][right_pointer];
    }
 
    return table[left_pointer][right_pointer] =
               max(cards[left_pointer] +
                       solve(cards, left_pointer + 1, right_pointer, turn + 1),
                   cards[right_pointer] +
                       solve(cards, left_pointer, right_pointer - 1, turn + 1));
  }
 
  else {
 
    if (left_pointer == right_pointer) {
      return table[left_pointer][right_pointer] = cards[left_pointer] * -1;
    }
 
    if (table[left_pointer][right_pointer] != 0) {
      return table[left_pointer][right_pointer];
    }
 
    if (cards[left_pointer] >= cards[right_pointer]) {
      return table[left_pointer][right_pointer] =
                 solve(cards, left_pointer + 1, right_pointer, turn + 1) -
                 cards[left_pointer];
    }
 
    else {
      return table[left_pointer][right_pointer] =
                 solve(cards, left_pointer, right_pointer - 1, turn + 1) -
                 cards[right_pointer];
    }
  }
}
 
int main() {
 
  int N, number_game = 1;
 
  do {
    cin >> N;
    if (N == 0)
      break;
 
    int cards[N];
    for (int i = 0; i < N; i++)
      cin >> cards[i];
 
    cout << "In game " << number_game
         << ", the greedy strategy might lose by as many as "
         << solve(cards, 0, N - 1, 1) << " points." << endl;
 
    memset(table, 0, sizeof(table[0][0]) * 2000 * 2000);
    number_game++;
  } while (N != 0);
 
  return 0;
} 

