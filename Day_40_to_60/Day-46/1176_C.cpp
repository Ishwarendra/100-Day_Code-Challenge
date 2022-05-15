#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
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

const vi num {4,8,15,16,23,42};
map<int, int> m; // (number -> index)

void solve()
{
	int n; cin >> n;
	for(int i = 0; i < 6; i++)
		m[num[i]] = i + 1;
	
	vi cnt(6);
	
	int grps = 0;
	
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		int cur_num = m[x] - 1;
	
		if (cur_num == 0){
			cnt[cur_num]++;
		}
		
		else if (cur_num > 0) {
			int prev_num = m[num[cur_num - 1]] - 1;
			if (cnt[prev_num] > cnt[cur_num])
				cnt[cur_num]++;
		}
	}
	
	grps = cnt[5];
	cout << n - 6*grps << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}