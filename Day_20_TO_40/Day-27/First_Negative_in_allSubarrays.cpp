#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int k;
        cin >> k;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{
    vector<long long> ans(n - k + 1);
    long long i = 0, j = 0;
    queue<long long> q;
    while (j < n)
    {
        if (a[j] < 0)
            q.push(a[j]);       
        if (j - i + 1 == k)
        {
            // Find answer
            if (q.empty())
                ans[i] = 0;
            else
            {
                ans[i] = q.front();
                if (a[i] == q.front())
                    q.pop();
            }

            // Slide the window
            i++;
        }
        j++;
    }

    return ans;
}