#include <iostream>
#include <vector>

const int N = 1e6 + 1;

long long phi[N];

void preprocess(int n)
{
    std::vector<int> prime;
    std::vector<bool> is_prime(n, true);

    for (int i = 2; i < n; i++)
    {
        if (is_prime[i])
        {
            phi[i] = i - 1;
            prime.push_back(i);
        }

        for (int j = 0; j < prime.size() and 1LL * i * prime[j] < n; j++)
        {
            is_prime[i * prime[j]] = false;

            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
        }
    }
}

int main()
{
    preprocess(N);
    for (int i = 1; i < N; i++)
        phi[i] += phi[i - 1];

    while (true)
    {
        int n;
        std::cin >> n;

        if (n == 0)
            break;

        std::cout << phi[n] << "\n";
    }
}