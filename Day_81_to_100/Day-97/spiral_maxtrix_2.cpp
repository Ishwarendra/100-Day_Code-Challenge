#include <bits/stdc++.h>
using namespace std;

template<typename T>
using v = vector<T>;

class Solution {
	void fill(v<v<int>> &matrix, int i1, int j1, int i2, int j2, int st)
	{
		if (i2 < i1)
			return;
			
		int x1 = i1, y1 = j1, x2 = i2, y2 = j2;
		
		while (y1 <= j2)
			matrix[i1][y1] = st++, y1++;
		y1 = j1;
		
		x1++;
		while (x1 <= i2)
			matrix[x1][j2] = st++, x1++;
		x1 = i1;
		
		y2--;
		while (y2 >= j1)
			matrix[i2][y2] = st++, y2--;
		y2 = j2;
		
		x2--;
		while (x2 > i1)
			matrix[x2][i1] = st++, x2--;
		x2 = i2;
		
		fill(matrix, i1 + 1, j1 + 1, i2 - 1, j2 - 1, st); 
	}
	
public:
    vector<vector<int>> generateMatrix(int n) {
  		int starting_num = 1;

  		vector<vector<int>> matrix(n, vector<int>(n));
		
		fill(matrix, 0, 0, n - 1, n - 1, 1);  		      
		
		return matrix;
    }
};

int main()
{
	Solution a;
	a.generateMatrix(4);
	return 0; 
}    