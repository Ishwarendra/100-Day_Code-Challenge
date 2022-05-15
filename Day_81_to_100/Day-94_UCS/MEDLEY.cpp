#include<bits/stdc++.h>

using i64 = long long;

// Function to solve for x, y in equation ax + by = 1 and also returns gcd(a, b)
i64 gcd(i64 a, i64 b, i64 &x, i64 &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}

	i64 x1, y1;

	i64 d = gcd(b, a % b, x1, y1);

	x = y1;
	y = x1 - y1 * (a / b);

	return d;
}

void solve()
{
	i64 d1, a1, d2, a2, L, R;
	std::cin >> d1 >> a1 >> d2 >> a2 >> L >> R;

	i64 x0, y0;

	i64 g = gcd(d1, d2, x0, y0);
	
	if ((a2 - a1) %  g)
	{
		std::cout << "0\n";
		return;
	}

	x0 *= (a2 - a1) / g;

	y0 *= (a2 - a1) / g;
	y0 *= -1;

	i64 c1 = d1 / g;
	i64 c2 = d2 / g;

	i64 shift = std::min(x0 / c2, y0 / c1);
	
	// Decrease x0, y0 value to minimum possible (one of them might become negative)
	x0 -= shift * c2;
	y0 -= shift * c1;
	
	// Shift x, y towards positive value
	while (x0 < 0 || y0 < 0)
	{
		x0 += c2;
		y0 += c1;
	}
	
	// Make x < (d2/g) and y < (d1/g)
	while (x0 >= c2 && y0 >= c1)
	{
		x0 -= c2;
		y0 -= c1;
	}

	i64 start = d1 * x0 + a1;
	i64 step = (d1 / g) * d2;

	if (start < L)
		start += ((L - start) / step)  * step;

	while (start < L)
		start += step;

	i64 missed_number_cnt = 0;

	if (start <= R)
		missed_number_cnt += ((R - start) / step) + 1;

	std::cout << missed_number_cnt << "\n";
}

int main()
{
	i64 t;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}