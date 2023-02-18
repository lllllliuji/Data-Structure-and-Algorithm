#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string str;
    cin >> str;

    int n = str.size();
    for (int i = 0; i < n; i++) {
        int ni = str[i] - '0';
        if (ni % 8 == 0) {
            cout << "YES\n" << ni << endl;
            return 0;
        }
        for (int j = i + 1; j < n; j++) {
            int nj = 10 * ni + (str[j] - '0');
            if (nj % 8 == 0) {
                cout << "YES\n" << nj << endl;
                return 0;
            }
            for (int k = j + 1; k < n; k++) {
                int nk = 10 * nj + (str[k] - '0');
                if (nk % 8 == 0) {
                    cout << "YES\n" << nk << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}