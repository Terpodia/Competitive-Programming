#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

bool P(vi &stails, ll C, ll minimum) {
  ll pos_actual = 0;
  C--;

  for (int i = 1; i < stails.size(); i++) {
    if (C == 0) return true;

    if (stails[i] - stails[pos_actual] >= minimum) {
      pos_actual = i;
      C--;
    }
  }

  return (C <= 0);
}

ll bs(vi &stails, ll C) {
  ll a = -1, b = stails[stails.size() - 1] - stails[0] + 1, mid;

  while (b - a > 1) {
    mid = (a + b) / 2;

    if (P(stails, C, mid))
      a = mid;
    else
      b = mid;
  }

  return (a == -1) ? 0 : a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t, N, C;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> N >> C;
    vi stails(N);

    for (int j = 0; j < N; j++) cin >> stails[j];

    sort(stails.begin(), stails.end());

    cout << bs(stails, C) << "\n";
  }

  return 0;
}
