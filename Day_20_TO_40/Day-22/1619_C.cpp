#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)           \
    for (int i = (start); i < (end); i++) \
        cout << (v[i]) << " ";            \
    cout << "\n";
#define logarr(v)                                       \
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

string convert(vector<int> &b, int id)
{
    string res;
    for (int i = id; i >= 0; i--)
    {
        string cur = to_string(b[i]);
        res += cur;
    }

    return res;
}

string add(string &a, string &b)
{
    int i = a.length() - 1, j = b.length() - 1;
    string c;
    while(i >= 0 and j >= 0)
    {   
        int dig1 = a[i] - '0', dig2 = b[j] - '0';
        int resultant = dig1 + dig2;
        string cur_dig = to_string(resultant);
        c = cur_dig + c;
        // reverse(all(c));
        i--, j--;
    }

    while(i >= 0){
        c = a[i] + c, i--;
        // reverse(all(c));
    }
    while(j >= 0){
        c = b[j] + c, j--;
    }

    return c;
}

bool not_valid(string &a, vi &b, string &c, int start)
{
    // cout << "ho\n";
    string b_num = convert(b, start);
    // cout << "hoa\n";
    string a_plus_b = add(a, b_num);
    return (a_plus_b != c); 
}

void solve()
{
    string a, s; // a + b = s
    cin >> a >> s;

    int i = a.length() - 1, j = s.length() - 1;

    vector<int> b; // final answer will be reverse of this

    while (i >= 0 and j >= 0)
    {
        // print(s[j], a[i], s[j] > a[i], s[j] - a[j]);
        if (s[j] >= a[i])
        { // bi is simply their diff
            b.push_back(s[j] - a[i]);
        }
        else // get diff of two digit of s and one digit of a
        {
            if (j == 0)
            {
                cout << "-1\n";
                return;
            }

            int cur_num = (s[j] - '0') + (s[j - 1] - '0') * 10;
            b.push_back(cur_num - (a[i] - '0'));

            j--;
        }

        i--, j--;
    }

    // if a isn't exhausted but s is then false
    if (i >= 0 and j < 0)
    {
        cout << "-1\n";
    }
    else
    {
        // if a is exhausted but s remains then add ele of s
        for (int id = j; id >= 0; id--)
            b.push_back(s[id] - '0');

        int start = b.size() - 1;
        for (int id = start; id >= 0; id--)
        {
            if (b[id] != 0)
            {
                start = id;
                break;
            }
        }

        if (not_valid(a, b, s, start))
        {
            cout << "-1\n";
            return;
        }

        for (int id = start; id >= 0; id--)
            cout << b[id];
        cout << "\n";
    }
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    // string a = "3465", b = "17236";
    // print(add(a, b))
}