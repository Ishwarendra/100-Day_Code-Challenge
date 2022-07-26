#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

std::vector<std::string> solve(std::vector<std::string>& words, int k)
{
    int n = std::size(words);

    auto make_word = [&](int i, int j) -> std::string
    {
        std::string ans;
        int words_len = 0, spaces = j - i;

        if (spaces == 0)
        {
            ans += words[i];
            while (std::size(ans) < k)
                ans += ' ';

            return ans;
        }

        // count the length of all words
        for (; i <= j; i++)
            words_len += std::size(words[i]);

        // compute the remaining spaces and blanks where you can fill those spaces
        int space_cnt = (k - words_len) / spaces;
        int extra = (k - words_len) % spaces;

        i = j - spaces;
        for (; i < j; i++)
        {
            ans += words[i];
            if (extra)
            {
                ans += ' ';
                extra--;
            }

            for (int _ = 0; _ < space_cnt; _++)
                ans += ' ';
        }
        ans += words[j];
        assert((int) std::size(ans) == k);
        return ans;
    };

    std::vector<std::string> justified_sentence;

    for (int i = 0; i < n; )
    {
        int cnt = 0;
        int length_sum = 0;

        int j = i;
        for (; j < n; j++)
        {
            length_sum += std::size(words[j]) + (cnt > 0 ? 1 : 0);
            cnt++;

            if (length_sum> k)
                break;
        }
        
        j--;
        std::string justified_line = make_word(i, j);
        justified_sentence.emplace_back(justified_line);
        print(i, j, justified_line)
        i = j + 1;  
    }

    return justified_sentence;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // std::vector<std::string> words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    // std::vector<std::string> words = {"abc", "de", "fg", "bfq", "fdgre"};
    std::vector<std::string> words
    {
        "the", "battle", "for", "soup", "versus", "salad", "is", "raging", "in", "the", "other", "room"
    };

    int k = 50;

    print(solve(words, k));

    return 0;
}