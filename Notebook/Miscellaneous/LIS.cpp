#include <bits/stdc++.h>
using namespace std;

void print(int i, vector<int>& p, vector<int>& a) {
  if (p[i] != -1) print(p[i], p, a);
  cout << a[i] << " ";
}

void LIS(vector<int> a) {
  vector<int> L, L_id, p((int)a.size(), -1);

  for (int i = 0; i < (int)a.size(); i++) {
    auto it = lower_bound(L.begin(), L.end(), a[i]);
    int j = (int)distance(L.begin(), it);

    if (j == (int)L.size()) {
      L.push_back(a[i]);
      L_id.push_back(i);
    } else {
      L[j] = a[i];
      L_id[j] = i;
    }

    if (j > 0) p[i] = L_id[j - 1];
  }

  cout << (int)L.size() << "\n";
  print(L_id[(int)L.size() - 1], p, a);
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  LIS(a);

  return 0;
}
