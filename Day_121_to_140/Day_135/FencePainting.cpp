#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	
	int st1, en1, st2, en2;
	std::cin >> st1 >> en1 >> st2 >> en2;
	
	std::cout << (en2 - st2) + (en1 - st1) - std::max(0, -std::max(st1, st2) + std::min(en1, en2));
	
	return 0;
}