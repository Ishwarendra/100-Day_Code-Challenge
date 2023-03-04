#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define print(...) 1;
#endif

using i64 = long long;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    using Point = std::array<int, 2>;

    Node *construct(std::vector<std::vector<int>> &a, Point start, Point end)
    {
        if (start[0] > end[0] or start[1] > end[1])
            return NULL;

        int size = end[1] - start[1] + 1;
        assert(size == end[0] - start[0] + 1);
        int value = -1;
        bool isLeaf = true;

        for (int i = start[0]; i <= end[0]; i++)
        {
            for (int j = start[1]; j <= end[1]; j++)
            {
                if (value == -1)
                    value = a[i][j];
                else if (value != a[i][j])
                {
                    isLeaf = false;
                    break;
                }
            }

            if (!isLeaf)
                break;
        }

        if (isLeaf)
            return new Node(!!value, isLeaf);

        Node *topLeft = construct(a, start, Point {start[0] + size / 2 - 1, start[1] + size / 2 - 1});
        Node *topRight = construct(a, Point {start[0], start[1] + size / 2}, Point {start[0] + size / 2 - 1, start[1] + size - 1});
        Node *bottomLeft = construct(a, Point {start[0] + size / 2, start[1]}, Point {start[0] + size - 1, start[1] + size / 2 - 1});
        Node *bottomRight = construct(a, Point {start[0] + size / 2, start[1] + size / 2}, end);

        return new Node(true, isLeaf, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(std::vector<std::vector<int>>& grid)
    {
        int n = std::size(grid);
        return construct(grid, Point {0, 0}, Point {n - 1, n - 1});
    }
};
int main()
{
    return 0;
}