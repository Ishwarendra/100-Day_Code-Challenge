#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> dx {1, 0, -1, 0, 1, -1, -1, 1};
	vector<int> dy {0, 1, 0, -1, 1, -1, 1, -1};
	
	bool bound(int i, int j, vector<vector<int>> &board)
	{
		int m = board.size(), n = board[0].size();
		
		return i >= 0 and j >= 0 and i < m and j < n;
	}
public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size(), n = board[0].size();
		vector<vector<int>> grid(m, vector<int>(n));
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int alive = 0, dead = 0;
				
				for (int d = 0; d < 8; d++)
				{
					if (bound(i + dx[d], j + dy[d], board))
					{
						alive += board[i + dx[d]][j + dy[d]] == 1;
						dead += board[i + dx[d]][j + dy[d]] == 0;
					}
				}
				
				if (board[i][j] == 1)
				{
					if (alive < 2)
						grid[i][j] = 0;
					else if (alive <= 3)
						grid[i][j] = 1;
					else
						grid[i][j] = 0;
				}
				else
				{
					if (alive == 3)
						grid[i][j] = 1;
				}
			}
		}
		
		board = grid;
	}
};

int main()
{
	return 0;
}