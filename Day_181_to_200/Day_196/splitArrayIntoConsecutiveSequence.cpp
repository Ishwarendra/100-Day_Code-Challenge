#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

class Solution {
public:
    bool isPossible(std::vector<int>& nums) 
    {
        int n = std::size(nums);
        std::map<int, int> rem, end;

        for (int i : nums)
            rem[i]++;

        for (int i = 0; i < n; ++i)
        {
            if (!rem[nums[i]])
                continue;

            if (end[nums[i] - 1])
                end[nums[i] - 1]--, end[nums[i]]++;
            else if (rem[nums[i] + 1] and rem[nums[i] + 2])
            {
                rem[nums[i] + 1]--, rem[nums[i] + 2]--;
                end[nums[i] + 2]++;
            }
            else
                return false;

            rem[nums[i]]--;
        }

        return true;
    }
};

bool isPossible(std::vector<int>& A) {
    std::unordered_map<int, int> left, end;
    for (int i : A) {
        left[i]++;
    }
    for (int i : A) {
        if (left[i] == 0) continue;
        left[i]--;
        if (end[i - 1] > 0) {
            end[i - 1]--;
            end[i]++;
        } else if (left[i + 1] > 0 && left[i + 2] > 0) {
            left[i + 1]--;
            left[i + 2]--;
            end[i + 2]++;
        } else {
            return false;
        }
    }
    return true;
}

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

// int main()
// {
//     Solution sol; int n; std::cin >> n; std::vector<int> a(n);
//     for (int i = 0; i < n; ++i)
//         std::cin >> a[i];

//     std::cout << std::boolalpha << sol.isPossible(a) << std::endl;
// }

int main()
{
    Solution sol;

    int t;
    std::cin >> t;

    while (t--)
    {
        int n = 100;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = get_rand(1, 4);

        std::sort(std::begin(a), std::end(a));
        if (isPossible(a) != sol.isPossible(a))
        {
            std::cout << "not omk :(\n";
            print(isPossible(a), sol.isPossible(a))
            for (int i = 0; i < n; i++)
                std::cout << a[i] << " \n"[i == n - 1];


            return 0;
        }
    }

    std::cout << "omk :)";

    return 0;
}