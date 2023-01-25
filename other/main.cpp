#include <iostream>

using namespace std;
const int N = 100010;
int child[N][2], cnt[N], idx;

void insert(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int b = num & (1 << i);
        if (!child[p][b]) child[p][b] = ++idx;
        p = child[p][b];
    }
    cnt[p]++;
}

int query(int num) {
    int p = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int b = num & (1 << i);
        if (child[p][1 - b]) {
            p = child[p][1 - b];
            ans = 2 * ans + 1;
        } else if (child[p][b]) {
            p = child[p][b];
            ans = 2 * ans;
        } else {
            return ans;
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int num;
        cin >> num;
        ans = max(ans, query(num));
        insert(num);
    }
    cout << ans << endl;
    return 0;
}