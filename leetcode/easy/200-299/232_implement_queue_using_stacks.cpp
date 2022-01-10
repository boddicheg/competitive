#include <iostream>
#include <vector>
#include <stack>
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

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class MyQueue
{
public:
    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (!m_st_main.empty())
        {
            while(!m_st_main.empty())
            {
                int top = m_st_main.top();
                m_st_support.push(top);
                m_st_main.pop();
            }
        }
        m_st_support.push(x);

        while(!m_st_support.empty())
        {
            int top = m_st_support.top();
            m_st_main.push(top);
            m_st_support.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int top = m_st_main.top();
        m_st_main.pop();
        return top;
    }

    /** Get the front element. */
    int peek()
    {
        return m_st_main.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return m_st_main.empty();
    }

private:
    std::stack<int> m_st_support;
    std::stack<int> m_st_main;
};


int main(int argc, char const *argv[])
{
    MyQueue m;
    m.push(1);
    m.push(2);
    m.push(3);
    std::cout << m.peek() << std::endl;
    std::cout << m.pop() << std::endl;
    std::cout << m.pop() << std::endl;
    std::cout << std::boolalpha << m.empty() << std::endl;

    return 0;
}
