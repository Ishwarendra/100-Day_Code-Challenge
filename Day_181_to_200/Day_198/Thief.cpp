#include <bits/stdc++.h>
using namespace std;
const int mod = 100000007;
int BinarySearch(int score, int guard, vector<int>& power) {
    int l = 0, r = power.size() - 1;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (power[mid]*guard > score) {
            ans = mid; // this bike is ok check if you can do it with smaller ones too?
            r = mid - 1; 
        }
        else l = mid + 1;
    }

    return (int)power.size() - l; // from index `l` to  `n - 1` we can take all bikes 
}
void solve() {
    int ts, tp; cin >> ts >> tp;
    int score = ts * tp;
    int n; cin >> n;
    vector<int> skill(n), power(n);
    for (int i = 0; i < n; i++) {
        cin >> skill[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    sort(skill.begin(), skill.end());
    sort(power.begin(), power.end());
    int ways = 1;
    for (int i = 0; i < n; i++) {
        int t = (BinarySearch(score, skill[i], power)); // no need for mod as this will be <= n
        if (t - i <= 0)
        {
            ways = 0;
            break;
        }
        else
        {
            ways *= (t - i); // multiply instead of adding. why? think a little 
            ways %= mod;
        }
    }
    cout << ways << endl;
}

int main() {
    solve();
    return 0;
}