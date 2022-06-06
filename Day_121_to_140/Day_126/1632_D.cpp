#include<bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

class SparseTable
{
    std::vector<std::vector<int>> mat;
    std::vector<int> p2;

    int power_of_two_less(int n)
    {
        int i = 1, cnt = 0;
        while (i < n)
            i = (i << 1), cnt++;

        return --cnt;
    }

    void build_gcd(int n, int m, const std::vector<int> &a)
    {
        mat.resize(n, std::vector<int>(m));
        // mat[i][j] => gcd of ele in range (i, i + 2^j);

        // Base case when range is of length-1
        for (int i = 0; i < n; i++)
            mat[i][0] = a[i];

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int start_1 = i;
                int start_2 = i + (1 << (j - 1));

                if (start_2 >= n or 2 * start_2 - i - 1 >= n)
                    break;

                mat[i][j] = std::__gcd(mat[start_1][j - 1], mat[start_2][j - 1]);
            }
        }
    }

public:
    SparseTable(const std::vector<int> &a)
    {
        int n = a.size();
        p2.resize(n + 1);

        for (int i = 1; i <= n; i++)
            p2[i] = p2[i / 2] + 1;

        int m = p2[n] + 1;

        build_gcd(n, m, a);
    }

    void print_sparse()
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int ele : mat[i])
                std::cout << ele << '\t';
            std::cout << '\n';
        }
    }

    int gcd(int l, int r)
    {
        int len = p2[r - l + 1];
        len--;

        int start_1 = l;
        int start_2 = r - (1 << len) + 1;

        return std::__gcd(mat[start_1][len], mat[start_2][len]);
    }
};


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
    
    SparseTable st(a);
    
    int l = 0, ans = 0, last = -1;    
    
    for (int r = 0; r < n; r++)
    {
        while (l < r and st.gcd(l, r) < r - l + 1)
            l++;
        
        if (st.gcd(l, r) == r - l + 1)
        {
            if (l > last)
                ans++, last = r;
        }
        
        print(l, r)
        std::cout << ans << " \n"[r == n - 1];
    }
    
	return 0;
}




