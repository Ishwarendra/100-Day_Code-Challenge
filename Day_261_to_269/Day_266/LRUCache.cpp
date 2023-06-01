#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class LRUCache
{
    const int capacity;
    std::unordered_map<int, std::list<std::array<int, 2>>::iterator> location;
    std::list<std::array<int, 2>> cache;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!location.count(key))
            return -1;

        auto [_key, value] = *location[key];
        cache.erase(location[key]);
        location.erase(key);
        cache.push_back({key, value});
        location[key] = std::prev(std::end(cache));
        return value;
    }

    void put(int key, int value)
    {
        if (location.count(key))
        {
            auto it = location[key];
            cache.erase(it);
            cache.push_back({key, value});
        }
        else
        {
            if (std::size(cache) == capacity)
            {
                location.erase(cache.front()[0]);
                cache.erase(std::begin(cache));
            }

            cache.push_back({key, value});
        }

        location[key] = std::prev(std::end(cache));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int n;
    std::cin >> n;

    LRUCache* obj = new LRUCache(n);
    int q;
    std::cin >> q;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 0)
        {
            int key;
            std::cin >> key;
            print(obj->get(key));
        }
        else
        {
            int k, v;
            std::cin >> k >> v;
            obj->put(k, v);
        }
    }
    
    return 0;
}