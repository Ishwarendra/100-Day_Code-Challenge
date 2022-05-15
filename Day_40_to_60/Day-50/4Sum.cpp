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

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	int n = nums1.size();
	
	map<int, int> m1;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			m1[-(nums1[i] + nums2[j])]++;
	}	
	
	int ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			ans += m1[nums3[i] + nums4[j]];
	}	
	
	return ans;	
}

int main()
{

}