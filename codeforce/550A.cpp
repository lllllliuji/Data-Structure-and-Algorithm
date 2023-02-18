#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    int n = str.size();
    vector<bool> f(n + 1, false);
    vector<bool> g(n + 1, false);
    for (int i = 0; i < n; i++) {
        // AB
        if (str[i] == 'B' && i > 0 && str[i - 1] == 'A') {
            f[i] = true;
        } 
        // BA
        if (str[i] == 'A' && i > 0 && str[i - 1] == 'B') {
            g[i] = true;
        }
    }
    
    bool flag = false;
    for (int i = 0, a = 0, b = 0; i < n; i++) {
        if (i >= 2) {
            if (f[i - 2]) a++;
            if (g[i - 2]) b++;
            if (b > 0 && f[i]) {
                flag = true;
                break;
            }
            if (a > 0 && g[i]) {
                flag = true;
                break;
            }
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}