#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int i = (start); i < (end); i++) cout << (v[i]) << " ";cout << "\n";
#define log(v) for(auto i = ((v).begin()); i != ((v).end()); i++) cout << *(i) << " "; cout << "\n";
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

set<char> vowel{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

bool is_vowel(char ch)
{
    return (vowel.find(ch) != vowel.end());
}

void solve()
{
    string s;
    getline(cin, s, '\n');
    for(int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != '?' and s[i] != ' ')
        {
            cout << (is_vowel(s[i]) ? "YES" : "NO") << "\n";
            return;
        }
    }
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}