#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        int min = (s.empty()) ? x : getMin();
        if (x <= min)
            s.push(std::make_pair(x, x));
        else
            s.push(std::make_pair(x, min));
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }

private:
    std::stack<std::pair<int, int>> s;
};

int main(int argc, char const *argv[])
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.getMin() << std::endl;
    return 0;
}
