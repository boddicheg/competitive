#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

template<typename T, typename K>
std::ostream &operator<<(std::ostream &ss, const std::pair<T, K> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

struct DefaultInt
{
    int i = -1;
};
std::ostream &operator<<(std::ostream &ss, const DefaultInt &p)
{
    ss << p.i;
    return ss;
}

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        std::unordered_map<std::string, DefaultInt> table;
        vector<std::string> result;

        int min_idx = std::numeric_limits<int>().max();

        for (int i = 0; i < list1.size(); ++i)
            table[list1.at(i)].i = i;

        for (int i = 0; i < list2.size(); ++i)
        {
            auto it = table.find(list2.at(i));
            if (it != table.end())
            {
                min_idx = std::min(min_idx, i + it->second.i);
                it->second.i += i;
            }
        }

        for (const auto &e : list2)
        {
            auto it = table.find(e);
            if (it != table.end())
            {
                if (it->second.i == min_idx)
                result.push_back(it->first);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<std::string> v1 = { "Shogun", "Tapioca Express", "Burger King", "Piatti", "KFC" };
    vector<std::string> v2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun", "Tapioca Express" };
    // vector<std::string> v1 = { "Shogun","Tapioca Express","Burger King","KFC" };
    // vector<std::string> v2 = { "Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun" };
    auto result = s.findRestaurant(v1 , v2);
    for (const auto &e : result)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}
