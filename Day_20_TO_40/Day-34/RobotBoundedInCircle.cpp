#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0, dir = 0;
        int dx[]{0, 1, 0, -1};
        int dy[]{1, 0, -1, 0};
        int n = instructions.length();

        for (int i = 0; i < n; i++)
        {
            // cout << dir <<  " ";
            if (instructions[i] == 'L')
                dir = (dir + 3) % 4;
            else if (instructions[i] == 'R')
                dir = (dir + 1) % 4;
            else
                x += dx[dir], y += dy[dir];
        }

        if (x == 0 and y == 0) // surely cycle
            return true;
        if (dir != 0) // not heading north if x, y non zero
            return true;

        return false;
    }
};

int main()
{
    return 0;
}