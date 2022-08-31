#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

vector<int> string_process(int n, string s, vector<int> dict)
{
    vector<int> cnt(26);
    int mx = -1;

    for (int i = 0; i < n; i++)
    {
        mx = s[i] - 'a';
        cnt[mx]++;

        for (int j = 0; j < 26; j++)
            if (cnt[j])
                mx = max(mx, j);

        if (dict[mx] == 1)
            rotate(cnt.begin(), cnt.end() - 1, cnt.end());
        else
            rotate(cnt.begin(), cnt.begin() + 1, cnt.end());
    }

    return cnt;
}

int main()
{
    int n;
    string s;

    cin >> n >> s;
    vector<int> dict(26);
    for (int i = 0; i < 26; ++i)
        cin >> dict[i];

    auto ans = string_process(n, s, dict);
    for (int i = 0; i < 26; i++)
        cout << ans[i] << " \n"[i == 25];

    return 0; 
}    