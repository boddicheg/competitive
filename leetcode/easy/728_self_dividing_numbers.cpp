#include <iostream>
#include <vector>
using namespace std;

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> result;
    for (int i = left; i <= right; i++)
    {
        if (i % 10 == 0) continue;
        if (i < 10)
        {
            result.push_back(i);
            continue;
        }
        else
        {
            int tested_value = i;
            int multiplier = 10;
            bool correct = true;
            while (tested_value > 0)
            {
                int digit = tested_value % multiplier;
                tested_value /= 10;

                if (digit == 0)
                {
                    correct = false;
                    break;
                }

                if (i % digit == 0)
                    continue;
                else
                {
                    correct = false;
                    break;
                }
            }
            if (correct) result.push_back(i);
        }

    }
    return result;
}

int main(int argc, char const *argv[])
{
    auto vec = selfDividingNumbers(66, 708);
    for (const auto &d : vec)
        std::cout << d << " ";
    std::cout << std::endl;
    return 0;
}