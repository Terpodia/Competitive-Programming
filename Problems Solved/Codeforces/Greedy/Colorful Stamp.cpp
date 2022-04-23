//   ______                  ____
//  / __/ /____  ___  ___   / __/______ ___
// _\ \/ __/ _ \/ _ \/ -_) / _// __/ -_) -_)
///___/\__/\___/_//_/\__/ /_/ /_/  \__/\__/
//                   ,,
//             */##/#%/@(.
//         **....(&((%,#/%.
//          ./%&,(((#@@#%%,
//           &@@@*,#//.(((@
//            .#(#*..,/%*
//           *#(*/%(&%#
//        ./%,.#/%&#(/**(.//&@@@,%
// /#&.% .&*****#//,.*%/,.*(#%(##/#
///%%.((,#/((.,*****////*/*///*(,/,
// #%%//,(/#,,,,,,,,,***/,******(%,
//  #&%/.#,/,,,,,,.*@#/,,,..,#%&***
//   *#**,%,@%%%%(&//(%(,.,.#((,(,,*
//    %//,,(@%((.(%&.(/#(*.*(#,(.*((
//    #((//#@((((//&(&(/.../,/.#*%##*
//     ,#(#( /(%#(((/*@/***.*,,*,@@/*(*
//    //*(,/(   %%&%##/((*.,(***(%**(/(/
//   ,#&#,.,#     (&(#*./#*,*/*,,.(#,*%&,
//  *#/(*,./#     (*,..@&/*..,,/**/./###%
//  %&#*/.(%*   ,(%##&..%*,,.,(//**./((*/
//  #@,((##     &&%#((%&(%,..,...*/#%##**/
//  //*#*/ * *  @(%@...((#*(//######%((///
//  /#./,* , . ,#(%/.....#(&#/*/(%(&(&#(#.
// /@@,,*/,# * (**/....../##,##%%#/((.***.
// &((,,%(&@.#(.,#,.....*/*/(.%@@@@*/*%**&
// *,*,#,.(/#&%//%........(/%.@@@@@*#.%&/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... Args>
void _dbg(istream_iterator<string> it, T& a, Args&... args) {
  cout << *it << "=" << a << " ";
  _dbg(++it, args...);
}

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n..................................................\n"
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

void set_IO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  set_IO();
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    s.push_back('W');
    int cntR = 0, cntB = 0;
    bool can = true;
    for (char c : s) {
      if (!can) break;
      if (c == 'W') {
        if (cntR == 0 && cntB == 0) continue;
        if (cntR == 0 || cntB == 0) can = false;
        cntR = 0, cntB = 0;
      } else
        (c == 'R') ? cntR++ : cntB++;
    }
    (can) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}

