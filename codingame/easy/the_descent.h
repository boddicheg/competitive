// https://www.codingame.com/ide/puzzle/the-descent

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while (1)
    {
        int idx = -1;
        int maxH = -1;
        for (int i = 0; i < 8; i++)
        {
            int mountainH;
            std::cin >> mountainH; std::cin.ignore();
            if (maxH < mountainH)
            {
                maxH = mountainH;
                idx = i;
            }
        }

        std::cout << idx << std::endl;
    }
}