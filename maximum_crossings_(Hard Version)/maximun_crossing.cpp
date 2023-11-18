#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <algorithm>


using namespace std;
using ll = long long;



const int MAX_N = 200010;

struct FenwickTree {
    vector<ll> bit;
    int n;

    FenwickTree(int n) : n(n), bit(vector<ll>(n, 0)) {}

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int A[MAX_N];

int solve() {
    int n;
    if (!(cin >> n)) return 1;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    FenwickTree T(n + 10);
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res += T.sum(A[i], n);
        T.add(A[i], 1);
    }
    cout << res << '\n';
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TET;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
    }
}
