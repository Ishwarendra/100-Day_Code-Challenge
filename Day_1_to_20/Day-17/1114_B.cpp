#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)           \
    for (int i = (start); i < (end); i++) \
        cout << (v[i]) << " ";            \
    cout << "\n";
#define log(v) for(auto i = ((v).begin()); i != ((v).end()); i++) cout << *(i) << " "; cout << "\n";
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

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.rbegin(), b.rend());

    multiset<ll> good_ele;
    ll tot_beauty = 0;
    for (int i = 0; i < m*k; i++)
        tot_beauty += b[i], good_ele.insert(b[i]);

    vector<int> ans;
    
    int cur_good_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        auto cur_itr = good_ele.find(a[i]);
        if (cur_itr != good_ele.end()) // found it
        {
            cur_good_cnt++;
            good_ele.erase(cur_itr);
            if (cur_good_cnt == m)
            {
                ans.push_back(i + 1);
                cur_good_cnt = 0;
            }
        }
    }
    print(tot_beauty);
    printarr(ans, 0, ans.size() - 1);
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}