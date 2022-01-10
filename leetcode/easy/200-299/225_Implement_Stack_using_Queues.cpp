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

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        std::queue<int> qq;

        int idx = 0;
        while (!q.empty())
        {
            if (q.size() > 1)
            {
                qq.push(q.front());
                q.pop();
            }
            else
                break;
        }
        int topq = q.front();
        q = qq;
        return topq;
    }

    /** Get the top element. */
    int top() {
        std::queue<int> qq;
        int topq = 0;
        int idx = 0;
        while (!q.empty())
        {
            if (q.size() == 1)
            {
                topq = q.front();
            }
            qq.push(q.front());
            q.pop();
        }
        q = qq;
        return topq;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};

int main(int argc, char const *argv[])
{
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    std::cout << myStack.top() << std::endl; // return 2
    std::cout << myStack.pop() << std::endl; // return 2
    std::cout << myStack.empty() << std::endl; // return False
    return 0;
}
