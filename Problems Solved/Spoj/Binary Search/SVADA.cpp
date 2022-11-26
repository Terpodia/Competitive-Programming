#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll T, N, M;

ll P(vii &monkeys, ll time) {
  ll sum = 0;

  for (int i = 0; i < monkeys.size(); i++) {
    sum += (time < monkeys[i].first)
               ? 0
               : (time - monkeys[i].first) / monkeys[i].second + 1;
  }

  return sum;
}

ll bs(vii &first_type, vii &second_type) {
  ll lo = -1, hi = T + 1, mid, c1, c2, ans = -1;

  while (hi - lo > 1) {
    mid = (hi + lo) / 2;

    c1 = P(first_type, mid);
    c2 = P(second_type, T - mid);

    if (c1 <= c2) {
      lo = mid;
      ans = max(ans, mid);
    }

    else
      hi = mid;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  cin >> N;
  vii first_type(N);

  for (int i = 0; i < N; ++i)
    cin >> first_type[i].first >> first_type[i].second;

  cin >> M;
  vii second_type(M);

  for (int i = 0; i < M; ++i)
    cin >> second_type[i].first >> second_type[i].second;

  cout << bs(first_type, second_type) << "\n";

  return 0;
}
