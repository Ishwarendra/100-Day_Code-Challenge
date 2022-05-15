#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)           \
    for (int i = (start); i < (end); i++) \
        cout << (v[i]) << " ";            \
    cout << "\n";
#define log(v)                                          \
    for (auto i = ((v).begin()); i != ((v).end()); i++) \
        cout << *(i) << " ";                            \
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

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

int longest_word(vector<string> &s)
{
    int maxi = 0;
    for(string &str : s)
    {
        if (str.length() > maxi)
            maxi = str.length();
    }
    return maxi;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s += '_';

    vector<string> out_vec, in_vec;
    string out_string, in_string;
    bool in_turn = false;

    string cur;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '_' and s[i] != '(' and s[i] != ')')
            cur += s[i];

        else
        {
            if (!cur.empty())
            {
                (in_turn) ? in_vec.push_back(cur) : out_vec.push_back(cur); // jiski turn us vec me insert
                cur = "";                                                   // reset
            }

            if (s[i] == '(')
                in_turn = true;
            else if (s[i] == ')')
                in_turn = false;
        }
    }

    if (!cur.empty())
        (in_turn) ? in_vec.push_back(cur) : out_vec.push_back(cur);

    int out_long = longest_word(out_vec);
    int in_word_cnt = in_vec.size();
    // log(out_vec);
    cout << out_long << " " << in_word_cnt << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}