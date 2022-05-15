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

class DSU
{
    int *par, *rnk;
    int conn_cnt;
public:
    DSU(int n)
    {
        par = new int[n];
        rnk = new int[n];
        for(int i = 0; i < n; i++)
            par[i] = i, rnk[i] = 1;

        conn_cnt = n;
    }

    ~DSU()
    {
        delete[] par; delete[] par;
    }

    int get(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = get(par[x]);
    }

    void unite(int x, int y)
    {
        int s1 = get(x), s2 = get(y);
        if (s1 != s2)
        {
            if (rnk[s1] < rnk[s2])
            {
                par[s1] = s2;
                rnk[s2] += rnk[s1];
            }
            else
            {
                par[s2] = s1;
                rnk[s1] += rnk[s2];
            }
            conn_cnt--;
        }
    }

    int connected_count()
    {
        return conn_cnt;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> lang(m + 1);
    for(int i = 0; i < n; i++)
    {
        int sz; cin >> sz;
        while(sz--)
        {
            int l; cin >> l;
            lang[l].push_back(i);
        }
    }
  
    DSU d(n);
    bool in = true;
    for(int i = 1; i <= m; i++)
    {
        if (lang[i].size() > 0)
            in = false;

        for(int j = 1; j < lang[i].size(); j++)
            d.unite(lang[i ][j - 1], lang[i][j]);
    }
    cout << (in ? d.connected_count() : d.connected_count() - 1) << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}