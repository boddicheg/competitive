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

std::ostream &operator<<(std::ostream &ss, const std::vector<int> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class RecentCounter {
public:
    RecentCounter() {}
    
    int ping(int t) {
        pings.push(t);
        while (pings.front() < t - 3000)
            pings.pop();
        return pings.size();
    }

private:
    std::queue<int> pings;
};


int main(int argc, char const *argv[])
{
    RecentCounter s;
    std::cout << "Result: " << s.ping(1) << std::endl;
    std::cout << "Result: " << s.ping(100) << std::endl;
    std::cout << "Result: " << s.ping(3001) << std::endl;
    std::cout << "Result: " << s.ping(3002) << std::endl;
    return 0;
}
