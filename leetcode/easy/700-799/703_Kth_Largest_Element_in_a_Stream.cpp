#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class KthLargest {
public:
    KthLargest(int k, const std::vector<int>& nums)
    : k(k)
    {
        for(auto&& e: nums)
        {
            l.push(e);
            if (l.size() > k) l.pop();
        }
    }
    
    int add(int val) {
        l.push(val);
        if (l.size() > k) l.pop();
        return l.top();
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> l;
    int k;
};

int main(int argc, char const *argv[])
{
    KthLargest s(3, {4, 5, 8, 2});

    std::cout << "Result: " << s.add(3) << std::endl;
    std::cout << "Result: " << s.add(5) << std::endl;
    std::cout << "Result: " << s.add(10) << std::endl;
    std::cout << "Result: " << s.add(9) << std::endl;
    std::cout << "Result: " << s.add(4) << std::endl;
    return 0;
}
