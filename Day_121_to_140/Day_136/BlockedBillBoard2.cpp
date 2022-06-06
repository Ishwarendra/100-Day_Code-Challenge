#include<bits/stdc++.h>

struct Rect
{
	int bl_x, bl_y, tr_x, tr_y;

	friend std::istream& operator >>(std::istream &is, Rect &r)
	{
		is >> r.bl_x >> r.bl_y >> r.tr_x >> r.tr_y;
		return is;
	}

	int area()
	{
		return (tr_x - bl_x) * (tr_y - bl_y); 
	}

	int intersection_area(Rect &r)
	{
		// returns intersection area between two rectangle
		int l = std::max(0, std::min(tr_x, r.tr_x) - std::max(bl_x, r.bl_x));
		int w = std::max(0, std::min(tr_y, r.tr_y) - std::max(bl_y, r.bl_y));

		return l * w;
	}
};

bool between(int x, int l, int r)
{
	// returns true if x lie between l and r, false otherwise
	return (x >= std::min(l, r) and x <= std::max(l, r));
}

int inside(Rect &r, int x, int y)
{
	// return true if point (x, y) lie inside rectangle r, false otherwise
	return between(x, r.bl_x, r.tr_x) and between(y, r.bl_y, r.tr_y);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	
	Rect lawn_mower, cow_feed;
	std::cin >> lawn_mower >> cow_feed;
	
	std::vector<int> x_coordinate {lawn_mower.bl_x, lawn_mower.tr_x};
	std::vector<int> y_coordinate {lawn_mower.bl_y, lawn_mower.tr_y};

	int covered_points = 0;

	for (auto x : x_coordinate)
	{
		for (auto y : y_coordinate)
			if (inside(cow_feed, x, y))
				covered_points++;
	}
	
	// If there are more than 2 covered points then surely the entire rectangle is covered
	if (covered_points > 2)
		std::cout << 0;
	// If only one or none of the points of lawn mower rectangle is covered then we have to cover lawn mower reactangle entirely.
	else if (covered_points <= 1)
		std::cout << lawn_mower.area();
	// Else find the common part and remove from lawn mower.
	else
		std::cout << lawn_mower.area() - cow_feed.intersection_area(lawn_mower);

	return 0;
}