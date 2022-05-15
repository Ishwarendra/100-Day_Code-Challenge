#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)              \
    for (int _i = (start); _i < (end); _i++) \
        cout << (v[_i]) << " ";              \
    cout << "\n";
#define log(v)                                                \
    for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
        cout << *(__i) << " ";                                \
    cout << "\n";
#define print(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << "\n";                            \
    };

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

// Also take care of each person power

void solve()
{
    int n;
    cin >> n;
    vi cnt(n + 1);
    int matches_cnt = (n * (n - 1)) / 2;
    vector<vector<bool>> winner(n + 2, vector<bool>(n + 2)); // winner[x][y] x and y ke match me x win (if winner[y][x] = true then x y ke match me y win)
    for (int i = 0; i < matches_cnt - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        cnt[x]++, cnt[y]++;
        winner[x][y] = true;
    }
    int x = 0, y = 0;

    for (int i = 1; i <= n; i++)
        if (cnt[i] == n - 2)
            x = i;

    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == n - 2)
        {
            y = i;
            break;
        }
    }

    // print(x, y);
    for (int i = 1; i <= n; i++)
    {
        if (x == i or y == i)
            continue;
        if (winner[x][i] != winner[y][i])
        {
            if (winner[x][i])
                cout << x << " " << y << "\n";
            else
                cout << y << " " << x << "\n";
            return;
        }
    }

    cout << x << " " << y << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}