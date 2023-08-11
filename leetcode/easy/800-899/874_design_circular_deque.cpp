#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}
int g_obj_counter = 0;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

struct QNode
{
    QNode *next;
    QNode *prev;
    int val;

    QNode(int _val)
        : next(nullptr)
        , prev(nullptr)
        , val(_val)
    {
        // g_obj_counter++;
    }

    ~QNode()
    {
        // g_obj_counter--;
    }
};

class MyCircularDeque
{
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
        : m_capacity(k)
        , m_size(0)
        , m_front(nullptr)
        , m_back(nullptr)
    {}

    ~MyCircularDeque()
    {
        while(m_front != nullptr)
            deleteFront();
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (m_size + 1 > m_capacity)
            return false;

        if (m_front == nullptr)
        {
            m_front = new QNode(value);
            m_back = m_front;
        }
        else
        {
            m_front->prev = new QNode(value);
            m_front->prev->next = m_front;
            m_front = m_front->prev;
        }
        m_size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (m_size + 1 > m_capacity)
            return false;

        if (m_front == nullptr)
        {
            m_front = new QNode(value);
            m_back = m_front;
        }
        else
        {
            m_back->next = new QNode(value);
            m_back->next->prev = m_back;
            m_back = m_back->next;
        }
        m_size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if(m_front == nullptr)
            return false;
        if(m_front->next == nullptr && m_front->prev == nullptr)
        {
            delete m_front;
            m_front = nullptr;
            m_back = nullptr;
        }
        else
        {
            QNode* tmp = m_front->next;
            delete m_front;
            m_front = tmp;
            m_front->prev = nullptr;
        }
        m_size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if(m_front == nullptr)
            return false;

        if(m_front->next == nullptr && m_front->prev == nullptr)
        {
            delete m_front;
            m_front = nullptr;
            m_back = nullptr;
        }
        else
        {
            QNode* tmp = m_back->prev;
            delete m_back;
            m_back = tmp;
            m_back->next = nullptr;
        }
        m_size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if(m_front != nullptr)
            return m_front->val;
        else
            return -1;
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if(m_back != nullptr)
            return m_back->val;
        else
            return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() const
    {
        return m_size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() const
    {
        return m_size == m_capacity;
    }

    void print()
    {
        if(m_front == nullptr)
            std::cout << "[]" << std::endl;
        QNode *tmp = m_front;
        std::cout << "[ ";
        while (tmp != nullptr)
        {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout << "]" << std::endl;
    }

private:
    size_t m_capacity;
    size_t m_size;
    QNode *m_front;
    QNode *m_back;
};

int main(int argc, char const *argv[])
{
    {
        MyCircularDeque obj(5);
        std::cout << std::boolalpha << obj.insertFront(1) << std::endl;
        std::cout << std::boolalpha << obj.insertFront(2) << std::endl;
        std::cout << std::boolalpha << obj.insertLast(2) << std::endl;
        std::cout << std::boolalpha << obj.insertLast(3) << std::endl;
        std::cout << std::boolalpha << obj.insertFront(3) << std::endl;
        obj.print();
        std::cout << std::boolalpha << obj.deleteFront() << std::endl;
        obj.print();
        std::cout << std::boolalpha << obj.deleteFront() << std::endl;
        obj.print();
        std::cout << std::boolalpha << obj.insertFront(2) << std::endl;
        std::cout << std::boolalpha << obj.insertFront(3) << std::endl;
        obj.print();
        std::cout << std::boolalpha << obj.deleteLast() << std::endl;
        obj.print();
        std::cout << std::boolalpha << obj.deleteLast() << std::endl;
        obj.print();
        std::cout << std::boolalpha << obj.insertLast(2) << std::endl;
        std::cout << std::boolalpha << obj.insertLast(3) << std::endl;
        obj.print();
    }

    std::cout << "Nodes left: " << g_obj_counter << std::endl;
    return 0;
}
