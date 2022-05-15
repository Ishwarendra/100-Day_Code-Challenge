#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 2);
            if (isBadVersion(mid))
                ans = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};

vector<string> fizzBuzz(int n)
{
    vector<string> ans;
    for(int i = 0; i < n; i++)
    {
        if (i % 15 == 0)
            ans.push_back("FizzBuzz")
        else if (i % 3 == 0)
            ans.push_back("Fizz");
        else if (i % 5 == 0)    
            ans.push_back("Buzz");
        else
            ans.push_back(to_string(i));
    }
    return ans;
}

int main()
{
    return 0;
}