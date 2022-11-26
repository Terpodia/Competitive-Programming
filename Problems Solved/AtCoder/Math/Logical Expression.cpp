#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

void setIO() { cin.tie(0)->sync_with_stdio(false); }

const int MAXN = 60;

int N;
string S[MAXN];

ll solve(int i) {
  if (i == 0) return 1;

  if (S[i - 1] == "AND")
    return solve(i - 1);
  else
    return (1ll << i) + solve(i - 1);
}

int main() {
  setIO();
  cin >> N;
  for (int i = 0; i < N; i++) cin >> S[i];

  cout << solve(N) << "\n";

  return 0;
}
