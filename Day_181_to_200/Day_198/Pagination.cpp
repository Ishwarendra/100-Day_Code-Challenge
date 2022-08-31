#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

vector<string> fetchItemsToDisplay(vector<vector<string>> items,
    int sortParameter, int sortOrder, int itemsPerPage, int pageNumber)
{
    int n = items.size();
    vector<vector<int>> a;

    for (int i = 0; i < n; i++)
    {
        auto item = items[i];
        a.push_back({i, stoi(items[i][1]), stoi(items[i][2])});
    }

    auto compare = [&](const vector<int> &x, const vector<int> &y) -> bool
    {
        if (sortParameter == 0)
        {
            int id1 = x[0], id2 = y[0];
            if (sortOrder == 0) // ascending
                return items[id1][0] < items[id2][0];
            else
                return items[id1][0] > items[id2][0];
        }
        else
        {
            if (sortOrder == 0)
                return x[sortParameter] < y[sortParameter];
            else
                return x[sortParameter] > y[sortParameter];
        }
    };
    stable_sort(a.begin(), a.end(), compare);

    int start = itemsPerPage * pageNumber;
    int end = std::min(n - 1, start + itemsPerPage - 1);

    vector<std::string> ans;
    for (int i = start; i <= end; i++)
    {
        int id = a[i][0];
        ans.push_back(items[id][0]);
    }

    return ans;
}

int main()
{
    int n;
    std::cin >> n;

    vector<vector<std::string>> items(n, vector<std::string>(3));
    for (int i = 0; i < n; ++i)
        std::cin >> items[i][0] >> items[i][1] >> items[i][2];

    int sortP, sortO, iperpage, pn;
    std::cin >> sortP >> sortO >> iperpage >> pn;

    print(fetchItemsToDisplay(items, sortP, sortO, iperpage, pn));
    return 0; 
}    