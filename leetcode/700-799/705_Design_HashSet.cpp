#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

constexpr int _hash_buckets = 100;

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    MyHashSet()
        : m_table(_hash_buckets, std::list<int>())
    {
    }

    void add(int key)
    {
        int hash = hash_function(key);

        for (auto it = m_table.at(hash).begin(); it != m_table.at(hash).end(); ++it)
        {
            if ((*it) == key)
            {
                return;
            }
        }

        m_table.at(hash).push_back(key);
    }

    void remove(int key)
    {
        int hash = hash_function(key);

        for (auto it = m_table.at(hash).begin(); it != m_table.at(hash).end(); ++it)
        {
            if ((*it) == key)
            {
                m_table.at(hash).erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int hash = hash_function(key);

        for (auto it = m_table.at(hash).begin(); it != m_table.at(hash).end(); ++it)
        {
            if ((*it) == key)
                return true;
        }
        return false;
    }

    void print() const
    {
        for (int i = 0; i < _hash_buckets; i++)
        {
            std::cout << "[" << i << "]";
            for (auto &&e : m_table.at(i))
            {
                std::cout << " -> " << e;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::list<int>> m_table;

    int hash_function(int x) const
    {
        return x % _hash_buckets;
    }
};

int main(int argc, char const *argv[])
{
    MyHashSet hashSet;
    hashSet.print();
    hashSet.add(1);
    hashSet.print();
    hashSet.add(2);
    hashSet.print();
    bool c1 = hashSet.contains(1); // returns true
    bool c2 = hashSet.contains(3); // returns false (not found)
    hashSet.add(2);
    hashSet.print();
    bool c3 = hashSet.contains(2); // returns true
    hashSet.remove(2);
    hashSet.print();
    bool c4 = hashSet.contains(2); // returns false (already removed)
    // std::cout << "Result: " << result << std::endl;
    return 0;
}