#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

struct Rect
{
	int x1, y1, x2, y2;
	
	friend std::istream &operator>>(std::istream &is, Rect &r) 
	{
		is >> r.x1 >> r.y1 >> r.x2 >> r .y2;
		return is;
	}
};

int square(int x)
{
	return x * x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	
	Rect a, b;
	std::cin >> a >> b;
	
	int x1 = std::min({a.x1, a.x2, b.x1, b.x2});
	int x2 = std::max({a.x1, a.x2, b.x2, b.x2});
	
	int y1 = std::min({a.y1, a.y2, b.y1, b.y2});
	int y2 = std::max({a.y1, a.y2, b.y2, b.y2});
	
	std::cout << square(std::max(x2 - x1, y2 - y1));
	
	return 0;
}