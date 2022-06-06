#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

struct Rectangle
{
	int x1, y1, x2, y2;
	
	int area()
	{
		return (y2 - y1) * (x2 - x1);
	}	
};

int intersection(Rectangle &a, Rectangle &b)
{
	int l = std::max(0, std::min(a.x2, b.x2) - std::max(a.x1, b.x1));
	int w = std::max(0, std::min(a.y2, b.y2) - std::max(a.y1, b.y1));
	
	return l * w;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	
	Rectangle a, b, t;
	std::cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	std::cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	std::cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
	
	std::cout << a.area() + b.area() - intersection(a, t) - intersection(b, t);
	
	return 0;
}