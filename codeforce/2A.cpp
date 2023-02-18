#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string name;
    int score;
    unordered_map<string, vector<pair<int, int>>> his;
    unordered_map<string, int> final_score;
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        final_score[name] += score;
        his[name].push_back({final_score[name], i});
    }
    int maxv = INT_MIN;
    for (auto&[name, score] : final_score) {
        maxv = max(maxv, score);
    }
    vector<string> candidate;
    for (auto&[name, score] : final_score) {
        if (score == maxv) {
            candidate.push_back(name);
        }
    }
    int time = n;
    string ans = "";
    for (string& name : candidate) {
        sort(his[name].begin(), his[name].end(), [&](const auto& a, const auto& b) {
            if (a.first < maxv && b.first < maxv) {
                return a.second < b.second;
            }
            else if (a.first >= maxv && b.first >= maxv) {
                return a.second < b.second;
            }
            else {
                return a.first < b.first;
            }
        });
        auto it = lower_bound(his[name].begin(), his[name].end(), maxv, [](const auto& pii, int v) {
            return pii.first < v;
        });
        if (it->second < time) {
            time = it->second;
            ans = name;
        }
    }
    cout << ans << endl;
    return 0;
}