#include <iostream>
#include <vector>
#include <bitset>
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

class Solution
{
public:
    // suck at memory but 100% at speed
    int bitwiseComplement1(int N)
    {
        if (N == 0)
            return 1;

        std::bitset<32> bs(N);
        std::string b = bs.to_string();
        std::string binary_trimmed(b.begin() + b.find_first_of('1'), b.end());
        for (size_t i = 0; i < binary_trimmed.size(); i++)
        {
            binary_trimmed[i] = (binary_trimmed[i] == '0') ? '1' : '0';
        }
        std::bitset<32> result(binary_trimmed);
        return result.to_ulong();
    }

    int bitwiseComplement(int N)
    {
        if (N == 0)
            return 1;
        int n = 1;
        while( n <= N)
            n *= 2;

        // std::cout << n -1  << " is " << (std::bitset<8>(n - 1).to_string()) << " " << N  << " is " << (std::bitset<8>(N).to_string()) << std::endl;
        
        return N ^ (n - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.bitwiseComplement(0);
    std::cout << "Result: " << result << std::endl;
    result = s.bitwiseComplement(5);
    std::cout << "Result: " << result << std::endl;
    result = s.bitwiseComplement(7);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
