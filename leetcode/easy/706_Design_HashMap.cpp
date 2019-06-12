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

class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
        : m_table(_hash_buckets, std::list<std::pair<int, int>>())
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int hash = hash_function(key);

        for (auto it = m_table.at(hash).begin(); it != m_table.at(hash).end(); ++it)
        {
            if ((*it).first == key)
            {
                (*it).second = value;
                return;
            }
        }

        m_table.at(hash).push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) const
    {
        int hash = hash_function(key);

        for (auto it = m_table.at(hash).begin(); it != m_table.at(hash).end(); ++it)
        {
            if ((*it).first == key)
                return (*it).second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int hash = hash_function(key);

        for (auto it = m_table.at(hash).begin(); it != m_table.at(hash).end(); ++it)
        {
            if ((*it).first == key)
            {
                m_table.at(hash).erase(it);
                return;
            }       
        }
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
    std::vector<std::list<std::pair<int, int>>> m_table;

    int hash_function(int x) const
    {
        return x % _hash_buckets;
    }
};

int main(int argc, char const *argv[])
{
    MyHashMap hashMap;
    hashMap.print();
    hashMap.put(1, 1);
    hashMap.print();
    hashMap.put(2, 2);
    hashMap.print();
    int val1 = hashMap.get(1);    // returns 1
    hashMap.print();
    int val2 = hashMap.get(3);    // returns -1 (not found)
    hashMap.print();
    hashMap.put(2, 1); // update the existing value
    hashMap.print();
    int val3 = hashMap.get(2);    // returns 1
    hashMap.print();
    hashMap.remove(2); // remove the mapping for 2
    hashMap.print();
    int val4 = hashMap.get(2);    // returns -1 (not found)
    hashMap.print();
    // std::cout << "Result: " << result << std::endl;
    return 0;
}

