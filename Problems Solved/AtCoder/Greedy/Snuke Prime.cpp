#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

#define sz(x) (int)x.size()

struct event {
  ll pos, val;

  bool operator<(const event& e) const {
    if (pos != e.pos) return pos < e.pos;
    return val < e.val;
  }
};

const int MAXN = 2e5;

int N;
ll C;
ll a[MAXN], b[MAXN], c[MAXN];

vector<event> events;

void setIO() { cin.tie(0)->sync_with_stdio(false); }

void create_events() {
  for (int i = 0; i < N; i++) {
    events.push_back({a[i], c[i]});
    events.push_back({b[i] + 1, -c[i]});
  }

  sort(events.begin(), events.end());
}

ll solve() {
  create_events();

  ll current_pos = 0, ret = 0, acc = 0;

  for (int i = 0; i < sz(events); i++) {
    if (current_pos != events[i].pos) {
      ret += min(C, acc) * (events[i].pos - current_pos);
      current_pos = events[i].pos;
    }

    acc += events[i].val;
  }

  return ret;
}

int main() {
  setIO();
  cin >> N >> C;

  for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

  cout << solve() << "\n";

  return 0;
}
