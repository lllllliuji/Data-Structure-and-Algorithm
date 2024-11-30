#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
    处理输入输出时，如果当前非循环已经是valid == false的话，依旧需要正常处理输入输出。
*/
struct loop {
    bool reachable;
    bool constant;
    string varialbe_name;
};
void solve() {
    int L;
    string complexity;
    cin >> L >> complexity;
    // cout << L << " " << complexity << endl;
    bool valid = true;
    int max_complexity = 0;
    int cur_complexity = 0;
    int cur_unreachalbe_loop_count = 0;
    stack<loop> st;
    unordered_set<string> existed_variables;
    while (L--) {
        string op;
        cin >> op;
        if (op == "F") {
            string i, x, y;
            cin >> i >> x >> y;
            if (!valid) continue;
            if (existed_variables.count(i)) {
                valid = false;
                continue;
            }
            existed_variables.insert(i);

            bool reachable = true;
            bool constant = true;
            if (x == "n" && y == "n") {
            } else if (x == "n") {
                reachable = false;
                cur_unreachalbe_loop_count += 1;
            } else if (y == "n") {
                constant = false;
                if (cur_unreachalbe_loop_count == 0) cur_complexity += 1;
            } else {
                int a = stoi(x), b = stoi(y);
                if (a > b) {
                    reachable = false;
                    cur_unreachalbe_loop_count += 1;
                }
            }
            st.push({reachable, constant, i});
        } else if (op == "E") {
            if (!valid) continue;
            if (st.empty()) {
                valid = false;
                continue;
            }
            auto [reachable, constant, variable_name] = st.top();
            st.pop();
            cur_unreachalbe_loop_count -= !reachable;
            if (cur_unreachalbe_loop_count == 0) cur_complexity -= !constant;
            existed_variables.erase(variable_name);
        }
        max_complexity = max(max_complexity, cur_complexity);
        // if (op == "F") cout << "F " << cur_complexity << " " << max_complexity << endl;
        // if (op == "E") cout << "E " << cur_complexity << " " << max_complexity << endl;
    }
    if (!st.empty() || !valid) {
        cout << "ERR" << endl;
    } else {
        string actual_complexity;
        if (max_complexity == 0) {
            actual_complexity = "O(1)";
        } else {
            actual_complexity = "O(n^" + to_string(max_complexity) + ")";
        }
        cout << (actual_complexity == complexity ? "Yes" : "No") << endl;
        // cout << complexity << " " << actual_complexity << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}