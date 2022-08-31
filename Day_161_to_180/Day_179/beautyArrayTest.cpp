#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif



int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n; cin >> n;

        vector<int> in(n + 1);

        for (int i = 1; i <= n; i++) cin >> in[i];

        for (int i = 1; i <= n; i++) in[i] += in[i - 1];

        map<int, bool> f;

        f[0] = 1;
        int ans = 0;
        int l = 0;
        for (int i = 1; i <= n; i++) {
            if (f[in[i]]) {
                while (in[l] != in[i]) f[in[l]] = 0, l++;

                l++;
            }
            f[in[i]] = 1;

            ans += i - l;
        }
        cout << ans << "\n";
    }
    return 0;
}