#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution {
	bool safe(vector<vector<char>> &board, int x, int y, char val)
	{
		for (int i = 0; i < 9; ++i)
			if (board[i][y] == val)
				return false;
		
		for (int i = 0; i < 9; ++i)
			if (board[x][i] == val)
				return false;
			
		x = (x / 3) * 3, y = (y / 3) * 3;
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (board[x + i][y + j] == val)
					return false;
		}
		
		return true;
	}
	
	bool helper(vector<vector<char>> &board, int i, int j)
	{
		if (i == 9)
			return true;
		
		if (j == 9)
			return helper(board, i + 1, 0);		
		if (board[i][j] != '.')
			return helper(board, i, j + 1);
		
		for (char to_put = '1'; to_put <= '9'; to_put++)
		{
			// if safe then put
			if (safe(board, i, j, to_put))
			{
				board[i][j] = to_put;
				
				if (helper(board, i, j + 1))
					return true;
				
				board[i][j] = '.';
			}
		}
		
		return false;
	}
		
public:
	void solveSudoku(vector<vector<char>>& board) 
	{
		helper(board, 0, 0);
	}
};

int main()
{

	return 0;
}