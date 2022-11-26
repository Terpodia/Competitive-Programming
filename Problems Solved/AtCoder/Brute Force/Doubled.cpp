#include <iostream>
using namespace std;
using ll = long long;

ll N;

void setIO() { cin.tie(0)->sync_with_stdio(false); }

ll calc(string s, int k) {
  if ((int)s.size() == k) {
    s += s;
    return (stoll(s) <= N) ? 1 : 0;
  }

  ll ret = 0;

  if ((int)s.size() == 0) {
    for (int i = 1; i <= 9; i++) ret += calc(s + to_string(i), k);

    return ret;
  }

  for (int i = 0; i <= 9; i++) ret += calc(s + to_string(i), k);

  return ret;
}

int main() {
  setIO();
  cin >> N;
  ll ans = 0;

  for (int i = 1; i <= 6; i++) ans += calc("", i);

  cout << ans << "\n";

  return 0;
}
