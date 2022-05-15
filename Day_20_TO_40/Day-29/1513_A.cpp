#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k > (n - 1)/2)
        cout << "-1\n";
    else
    {
        vector<int> ans(n);
        int mini = 1, maxi = n;
        bool min_turn = true;
        for(int i = 0; i < n; i++)
        {
            if (min_turn)
                ans[i] = mini, mini++;
            else
                ans[i] = maxi, maxi--;
            min_turn = not min_turn;
        } 

        sort(ans.begin() + 2*k + 1, ans.end());
        log(ans);
    }
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}