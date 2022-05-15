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
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

class DSU
{
    int *par;
    int unconnected_cn;
public:
    DSU(int n)
    {
        unconnected_cn = n;
        par = new int[n];

        for(int i = 0; i < n; i++)
            par[i] = i;
    }

    int get(int x)
    {
        if (par[x] == x)
            return x;
        return get(par[x]);
    }

    void unite(int x, int y)
    {
        int s1 = get(x), s2 = get(y);
        if (s1 != s2)
        {
            par[y] = x;
        }
    }

    void disunite(int x, int y)
    {
        int s1 = get(x), s2 = get(y);
        if (s1 == s2)
        {
            unconnected_cn++;
            par[y] = y;
        }
    }

    int unconnected_comp()
    {
        return unconnected_cn;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}