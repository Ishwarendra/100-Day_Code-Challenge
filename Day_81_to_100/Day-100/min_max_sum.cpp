#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(vector<int> &arr, int n , int k)
{

    int miv = INT_MAX, mi, mav = INT_MIN, ma, cum_sum = 0, i = 0;
    while (i < n)
    {
        if (miv < arr[i])
        {
            miv = arr[i];
            mi = i;
        }
        if (mav < arr[i])
        {
            mav = arr[i];
            ma = i;
        }
        if (i - st + 1 == k)
        {
            cum_sum += miv + mav;
            ++st;
            if (mi < st)
                miv = INT_MAX;
            if (ma < st)
                mav = INT_MIN;
        }
        ++i;
    }
    return cum_sum;
}

int main()
{
    vector<int> a {2, 3, 1, 4};
    int n = a.size();
    int k = 2;

    cout << SumOfKsubArray(a, n, k);

    return 0;
}