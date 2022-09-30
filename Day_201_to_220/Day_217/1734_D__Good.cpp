#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = k, r = k, cur = a[k];
    bool check_left = 1, check_right = 1;
    while(l > 1 && r < n && (check_left || check_right)) {
        if(check_left) {
            int j = l - 1, temp = cur;
            check_left = 0;
            while(j > 0) {
                temp += a[j];
                if(temp >= cur) {
                    cur = temp;
                    l = j;
                    check_left = 1;
                    check_right = 1;
                }
                if(temp < 0) break;
                -- j;
            }
            if(j == 0) l = 1;
        }
        if(check_right) {
            int j = r + 1, temp = cur;
            check_right = 0;
            while(j <= n) {
                temp += a[j];
                if(temp >= cur) {
                    cur = temp;
                    r = j;
                    check_right = 1;
                    check_left = 1;
                }
                if(temp < 0) {
                    break;
                }
                ++ j;
            }
            if(j == n + 1) r = n;
        }
    }
    r = min(n, r);
    l = max(l, 1ll);
    cout << (l == 1 || r == n ? "YES" : "NO") << '\n';
}

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }

    return 0;
}