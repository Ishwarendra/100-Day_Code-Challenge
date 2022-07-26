#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int getAns(int i,int j,const string &a,const string &b,vector<vector<int>> &dp)
{
    if(i>=a.length() && j>=b.length()) return true;
    if(i>=a.length() || j>=b.length()) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    if(b[j]=='?')
    {
        dp[i][j] = getAns(i+1,j+1,a,b,dp);
    }
    else if(b[j]=='*')
    {
        dp[i][j] = getAns(i+1,j,a,b,dp) || getAns(i,j+1,a,b,dp) || getAns(i+1,j+1,a,b,dp);
    }
    else
    {
        if(a[i]==b[j]) dp[i][j] = getAns(i+1,j+1,a,b,dp);
        else dp[i][j] = false;
    }
    return dp[i][j];
}

int isMatch(const string A, const string B) {
    vector<vector<int>> dp(A.length(),vector<int>(B.length(),-1));
    bool ans =  getAns(0,0,A,B,dp);

    for (auto i : dp)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << "\n";
    }

    return ans;
}

int main()
{
    std::string a, v;
    std::cin >> a >> v;

    std::cout << isMatch(a, v);
    return 0; 
}    