#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        for(int i = 1; i <= n; i++)
        {
            if(i % 3 == 0 && i % 5 == 0) result.push_back("FizzBuzz");
            else if(i % 3 == 0) result.push_back("Fizz");
            else if(i % 5 == 0) result.push_back("Buzz");
            else result.push_back(std::to_string(i));
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    print(s.fizzBuzz(20));
    return 0;
}
