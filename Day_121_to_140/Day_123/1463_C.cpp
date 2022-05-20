#include <bits/stdc++.h>

using i64 = int64_t;

// #define LOCAL 1

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

const i64 inf = 1e12;

template<typename T1, typename T2>
bool between(T1 a, T2 b, T1 c)
{
	return (b >= std::min(a, c) and b <= std::max(a, c));
}

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<i64> t(n + 1), x(n + 1);
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> t[i] >> x[i];
		
		if (i)
			t[i] -= t[0];
	}
	
	t[0] = 0;
	t.back() = inf;
	
	if (n == 1)
	{
		std::cout << "1\n";
		return;
	}
	
	i64 success = 0;
	i64 cur = 0, ignore = -1, to_reach = 0;
	
	int dir;
	
	for (int i = 0; i < n; i++)
	{
		if (t[i] < ignore)
		{
			// ignore command
			i64 st = cur;
			
			cur += dir * (t[i + 1] - t[i]);
			
			// if we go beyond the command's pos (x[i]) then change cur
			if (abs(cur) > abs(to_reach))
				cur = to_reach;
			
			// if we ever reached x[i]
			if (between(st, x[i], cur))
				success++;
			
			print(i, cur, success);
		}
		else
		{
			// don't ignore command
			ignore = t[i] + abs(cur - x[i]); // upto what time you should ignore
			to_reach = x[i]; // where command wants you to reach
			dir = (x[i] - cur < 0 ? -1 : 1); // direction
			
			if (x[i] == cur)
				dir = 0;
			
			i64 st = cur;
			cur += dir * (t[i + 1] - t[i]);
			
			// robot reaches destination while travelling		
			if (between(st, x[i], cur))		
				cur = x[i], success++;
				
			print(i, cur, success);
		}
	}
	
	std::cout << success << "\n";
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