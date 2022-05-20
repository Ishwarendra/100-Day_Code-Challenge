#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
  #define trace(x...) 42
#endif

void solve()
{
	std::string s;
	std::cin >> s;
	
	if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5])	
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
	
	trace("yoyo");
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}