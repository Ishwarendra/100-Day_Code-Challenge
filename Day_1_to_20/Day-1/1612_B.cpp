#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> left_half(n/2);
    vector<int> right_half(n/2);

    left_half[0] = a;
    right_half[0] = b;

    int num = n;
    bool possible = true;

    for(int i = 1; i < n/2; i++)
    {
        if (num == b)
            num--;
        if (num <= 0 or num <= a)
        {
            possible = false;
            break;
        }

        left_half[i] = num;
        num--;
    }

    num = 1;
    for(int i = 1; i < n/2; i++)
    {
        if (num == a)
            num++;
        if (num >= b)
        {
            possible = false;
            break;
        }

        right_half[i] = num;
        num++;
    }

    if (not possible)
        cout << "-1\n";
    else    
    {
        for(int &i : left_half) 
            cout << i << " ";
        for(int &i : right_half)
            cout << i << " ";
        cout << "\n";
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}