#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int d = 0;
    int m = 0;
    int last = min(k, n);
    vector< int > t(n, 0);
    set< int > now;
    for (int i = 0; i < min(n, k); ++i) {
        now.insert(i);
    }
    set< int > ans;
    while (now.size() > 0) {
        assert(now.size() <= k);
        for (auto u : now) {
            ++t[u];
            if (t[u] == d) {
                ans.insert(u);
            }
        }
        vector< int > ok;
        for (auto u : now) {
            if (t[u] == a[u]) {
                ok.push_back(u);
                ++m;
            }
        }
        for (auto u : ok) {
            now.erase(u);
            if (last < n) {
                now.insert(last);
                ++last;
            }
        }
        d = (100 * m + n / 2) / n;
    }
    cout << ans.size() << '\n';
    return 0;
}
