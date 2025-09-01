#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> w1, w2; // weight 1 and weight 2 items separate
    for (int i = 0; i < n; i++) {
        int W, C;
        cin >> W >> C;
        if (W == 1) w1.push_back(C);
        else w2.push_back(C);
    }

    sort(w1.rbegin(), w1.rend()); // weight 1 descending
    sort(w2.rbegin(), w2.rend()); // weight 2 descending

    // prefix sums
    vector<long long> pre1 = {0};
    for (int x : w1) pre1.push_back(pre1.back() + x);
    vector<long long> pre2 = {0};
    for (int x : w2) pre2.push_back(pre2.back() + x);

    int M = w1.size() + 2 * w2.size(); // max capacity
    vector<long long> res(M + 1, 0);

    // iterate over number of weight-2 items
    for (int k2 = 0; k2 < pre2.size(); k2++) {
        long long val2 = pre2[k2];
        int used_weight = k2 * 2;
        for (int k1 = 0; k1 < pre1.size() && used_weight + k1 <= M; k1++) {
            res[used_weight + k1] = max(res[used_weight + k1], val2 + pre1[k1]);
        }
    }

    for (int i = 1; i <= M; i++) cout << res[i] << " ";
    cout << endl;

    return 0;
}
