#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

void setIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  setIO();
  int N;
  cin >> N;
  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  sort(a, a + N);

  ll suff[N];
  suff[N - 1] = a[N - 1];
  for (int i = N - 2; i >= 0; i--) suff[i] = suff[i + 1] + a[i];

  ll ans = 0;

  for (int i = 0; i < N - 1; i++) {
    ans += suff[i + 1] - a[i] * (N - 1 - i);
  }

  cout << ans << "\n";

  return 0;
}
