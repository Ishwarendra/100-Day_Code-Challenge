#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

const int inf = (int)999999920999999999;

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res = res * a;
        }
    }
    return res;
} 

void solve()
{
	int n, k; cin >> n >> k;
	k++;
	vi den(n);
	
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		den[i] = power(10, x);
	}
    
    vi notes(n);
    
    notes.back() = inf;
    
    for(int i = 0; i < n - 1; i++)
        notes[i] = (den[i + 1]/den[i]) - 1;
    
    // log(notes);
    // log(den);
        
    int ans = 0, i; 
    for(i = 0; i < n; i++)
    {
        int cur_note = min(k, notes[i]);
        ans += cur_note * den[i];
        
        k -= cur_note;
        
        if (k == 0)
            break;
    } 
    
    cout << ans << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}