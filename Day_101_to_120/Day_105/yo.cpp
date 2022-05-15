#include <bits/stdc++.h>
using namespace std;

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};


int Betra_Pigeon(string &s)
{
	int n = s.length();
	
	bool no_issue = true;
	vector<int> issue;
	
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == 'R' and s[i + 1] == 'L')
		{
			no_issue = false;
			issue.push_back(i + 1);
		}
	}
	
	if (no_issue)
		return 0;
	else
	{
		// either make all left or all right
		int last = issue.back();
		int ans = count(s.begin(), s.begin() + last + 1, 'R');
		ans = min(ans, count(s.begin(), s.begin() + last + 1, 'L'));
		return ans;
	}
}

int main()
{
	string s;
	cin >> s;
	cout << Betra_Pigeon(s);
	return 0; 
}    