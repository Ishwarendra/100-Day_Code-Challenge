#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
		
	std::stack<int> st;
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (st.empty())
			st.push(a[i]);
		else if (st.top() < a[i])
			st.push(a[i]);
	}
	
	std::cout << st.size() - 1 << "\n";
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