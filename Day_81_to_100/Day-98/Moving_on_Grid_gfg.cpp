#include <bits/stdc++.h>
using namespace std;


class Solution {
	vector<vector<int>> dirs { {1, 0}, {2, 0}, {3, 0}, {0, 1}, {0, 2}, 
	{0, 3}, {0, 4}, {0, 5}, {0, 6} };
public:
	string movOnGrid(int r, int c) {
		r = (r - 1) % 4;
		c = (c - 1) % 7;
		
		if (r == c)
			return "ARYA";
		return "JON";
	}
};


int main()
{

	return 0;
}