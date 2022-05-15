#include <bits/stdc++.h>
using namespace std;

template<class T>
T power(T a, int b, int mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
} 

class Solution{   
public:
    string stringPartition(string S, int a, int b)
    {
    	int n = S.length();
    	
    	vector<int> pref_rem(n), suff_rem(n);
    	
    	pref_rem[0] = (S[0] - '0') % a;
    	
    	for (int i = 1; i < n; i++)
    		pref_rem[i] = ((10 * pref_rem[i - 1]) % a + (S[i] - '0') % a) % a;
    	
    	suff_rem[n - 1] = (S[n - 1] - '0') % b;
    	
    	for (int i = n - 2; i >= 0; i--)
    		suff_rem[i] = (suff_rem[i + 1] + ((power(10LL, n - i - 1, b) * 1LL * (S[i] - '0'))) % b) % b;
    	
        // for (int i = 0; i < n; i++)
        // {
        //     cout << i << ": " << pref_rem[i] << " -- " << suff_rem[i] << "\n";
        // }
    	
    	for (int i = 0; i < n - 1; i++)
    	{
    		if (pref_rem[i] == 0 and suff_rem[i + 1] == 0)
    			return S.substr(0, i + 1) + " " + S.substr(i + 1);
    	}
    	
    	return "-1";
    }
};


int main()
{
    string s; int a, b;
    cin >> s >> a >> b;
    
	Solution sol;
	cout << sol.stringPartition(s, a, b);
	return 0; 
}    