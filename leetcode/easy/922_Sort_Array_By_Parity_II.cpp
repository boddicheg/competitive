#include <iostream>
#include <vector>
#include <set>
#include <utility>

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

std::ostream &operator<<(std::ostream &ss, const std::vector<int> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class SolutionAPPR1
{
public:
    std::vector<int> sortArrayByParityII(const std::vector<int> &A)
    {
        std::vector<int> even;
        std::vector<int> odd;
        std::vector<int> result;
        for (size_t i = 0; i < A.size(); i++)
        {
            if (A.at(i) % 2 == 0)
                even.push_back(A.at(i));
            else
                odd.push_back(A.at(i));
        }

        for (size_t i = 0, j = 0, k = 0; i < A.size(); i++)
        {
            if (i % 2 == 0)
                result.push_back(even.at(j++));
            else
                result.push_back(odd.at(k++));
        }

        return result;
    }
};

class SolutionAPPR2
{
public:
    std::vector<int> sortArrayByParityII(std::vector<int> &A)
    {
        int j = 1;
        for (size_t i = 0; i < A.size(); i += 2)
        {
            if (A.at(i) % 2 == 1)
            {
                while(A.at(j) % 2 == 1)
                    j += 2;
                
                std::swap(A.at(i), A.at(j));
            }
            
        }

        return A;
    }
};

int main(int argc, char const *argv[])
{
    SolutionAPPR2 s;
    std::vector<int> data = {4, 2, 5, 7};
    auto result = s.sortArrayByParityII(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
