#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

class Solution {
public:
    int hammingWeight(uint32_t n) {
  		return __builtin_popcount(n);      
    }
};

int main()
{
	return 0; 
}    